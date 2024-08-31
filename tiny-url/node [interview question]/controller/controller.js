import bs58 from 'bs58'
import { port } from '../index.js';

/*****  Storage variables ********/
let id = 1;
let urlMap = new Map();     // alias->{longUrl,createdAt,ttl_seconds}
let timeMap = new Map();    // alias->{time1,time2,....} for analytics


/***** helper functions  ********/

const deleteAliasFromMaps=(alias)=>{
    urlMap.delete(alias);
    timeMap.delete(alias);
}

const ttlChecker = async ()=>{
    setInterval(() => {
        for( const [key,val] of urlMap){
            const currTime = new Date;
            if(currTime.getTime()-val.createdAt.getTime()>=val.ttl_seconds*1000){
                deleteAliasFromMaps(key);
            }
        }
        
    }, 200);
}


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
        
        const createdAt = new Date();
        urlMap.set(custom_alias,{long_url,createdAt,ttl_seconds})
        console.log(urlMap.get(custom_alias))
        
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
const deleteAlias = (req,res)=>{
    try{
        const alias = req.params.alias;
        deleteAliasFromMaps(alias);
        return res.status(200).json({ message: "Aliases deleted" });

    }catch(err){
        return res.status(404).json({ message: "Error deleting alias" });
    }
}

// key update cant be dont directly in javascipt
const updateAlias = (req,res)=>{
    try{
        const oldAlias = req.params.alias
        const {custom_alias,ttl_seconds} = req.body;

        const detials = urlMap.get(oldAlias);
        detials.ttl_seconds = ttl_seconds;  // set new ttl

        const access_times = timeMap.get(oldAlias);

        urlMap.delete(oldAlias);
        timeMap.delete(oldAlias);

        urlMap.set(custom_alias,detials);
        timeMap.set(custom_alias,access_times);

        return res.status(200).json({ message: "updated alias" });

    }catch(err){
        return res.status(404).json({ message: "Error updating alias" });
    }
}

export {
    shorten,
    getLongURLfromAlias,
    analytics,
    deleteAlias,
    updateAlias,
    ttlChecker
} 