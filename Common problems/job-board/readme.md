### Job Board 

## Schema needed for job, applicant in database 

job will have {
    jobId : int,        // every job will have a uniq ID
    Company: string,
    Date posted : date,
    isFilled : boolean(false)
}

applicant will have{
    userID: int,        // every user will have a uniq userID
    name : string,
    phone: string,
    email: string,
}


## For each jobID, we will store number of applicants

