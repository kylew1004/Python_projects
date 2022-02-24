import csv

def save_files(jobs) :
    file = open("jobs.csv", mode="w", encoding='UTF-8')
    writer = csv.writer(file)
    writer.writerow(["company","title","link"])
    for job in jobs :
        writer.writerow(list(job.values()))
    return