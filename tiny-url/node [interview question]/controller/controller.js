import bs58 from 'bs58'
import { port } from '../index.js';

/*****  Storage variables ********/
let id = 1;
let urlMap = new Map();
let timeMap = new Map();   // alias->{time1,time2,....}


/*****  API definitions ********/
const shorten = (req,res)=>{
    try{
        let {long_url,custom_alias,ttl_seconds=120} = req.body;

        // encoding using base 58
        if(!custom_alias){
            const buffer = Buffer.alloc(4);
            buffer.writeUInt32BE(id, 0); // Convert number to a Buffer
            custom_alias = bs58.encode(buffer);
            ++id;
        }
    
        urlMap.set(custom_alias,{long_url,ttl_seconds})
        console.log(custom_alias+" : "+long_url+","+ttl_seconds )
        
        return res.status(200).json({short_url:`http:localhost:${port}/`+custom_alias})

    }catch(err){
        console.error(err);
        return res.status(500).json({ error: 'Internal Server Error' });
    }
}

const getLongURLfromAlias = (req,res)=>{
    try{
        const alias = req.params.alias;
        const responseFromMap = urlMap.get(alias);

        if(responseFromMap){
            console.log(responseFromMap)
            const long_url = responseFromMap.long_url;

            const currentTime = new Date();

            // analytics - add to time map. need to initialise array for first element
            if(timeMap.has(alias)){
                const access_times = timeMap.get(alias);
                access_times.push(currentTime);
                timeMap.set(alias,access_times);
            }else{
                const access_times = [currentTime]
                timeMap.set(alias,access_times);
            }

            return res.redirect(long_url);
        }else{
            return res.status(404).json({ message: "Not Found"});
        }

    }catch(err){
        console.log(err);
        return res.status(500).json({ error: 'Internal Server Error' });
    }
}

const analytics = (req,res)=>{
    const myAlias = req.params.alias;
    const responseFromUrlMap = urlMap.get(myAlias);
    const responseFromTimeMap = timeMap.get(myAlias);

    // Check if data exists in both maps
    if (responseFromUrlMap && responseFromTimeMap) {
        const count = responseFromTimeMap.length;

        if (count > 0) {
            return res.status(200).json({
                alias: myAlias,
                long_url: responseFromUrlMap.long_url,
                access_count: count,
                access_times: responseFromTimeMap,
            });
        } else {
            return res.status(200).json({ message: "No access times found" });
        }
    } else {
        return res.status(404).json({ message: "Alias not found" });
    }

}
const deleteAlias = (req,res)=>{}
const updateAlias = (req,res)=>{}

export {
    shorten,
    getLongURLfromAlias,
    analytics,
    deleteAlias,
    updateAlias
} 