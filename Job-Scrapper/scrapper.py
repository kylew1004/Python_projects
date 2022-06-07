import requests
from bs4 import BeautifulSoup

def scrap_jobs(keyword) :

  db= []

  #weworkremotely scrapping
  url1 = f"https://weworkremotely.com/remote-jobs/search?utf8=%E2%9C%93&term={keyword}"
  result1 = requests.get(url1)
  soup1 = BeautifulSoup(result1.text, "html.parser")
  table1_1 = soup1.find_all("section",{"class":"jobs"})

  for i in table1_1:
      if i:
          table1_2 = i.find_all("li")
          for j in table1_2[0:-1]:
              company = j.find("span", {"class": "company"}).get_text()
              title = j.find("span", {"class": "title"}).get_text()
              links = "https://weworkremotely.com"+j.find_all("a")[1]["href"]
              db.append({"company": company, "title": title,"links":links})
    
  #romteok scrapping
  url2 = f"https://remoteok.io/remote-{keyword}-jobs"
  headers = {'User-Agent': 'Mozilla/5.0 (Macintosh; Intel Mac OS X 10_9_3) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/35.0.1916.47 Safari/537.36'}
  result2 = requests.get(url2,headers=headers)
  soup2 = BeautifulSoup(result2.text, "html.parser")
  table2 = soup2.find_all("tr",{"class":"job"})
  
  for i in table2 :
    company = i.find("td",{"class":"company"}).find("h3").string
    title = i.find("td",{"class":"company"}).find("h2").string
    links = "https://remoteok.io/remote-jobs/106620-remote-senior-software-developer-steadily"+i.find("td",{"class":"company"}).find("a",{"class":"preventLink"})["href"]
    db.append({"company":company,"title":title,"links":links})
  
  #stackoverflow scrapping

  url3 = f"https://stackoverflow.com/jobs?q={keyword}"

  def get_last_page():
    result = requests.get(url3)
    soup = BeautifulSoup(result.text, "html.parser")
    pages = soup.find("div", {"class": "s-pagination"}).find_all("a")
    last_page = pages[-2].get_text(strip=True)
    return int(last_page)

  def extract_job(html):
      title = html.find("h2").find("a")["title"]
      company, location = html.find("h3").find_all("span", recursive=False)
      company = company.get_text(strip=True)
      
      job_id = html['data-jobid']
      return {
          'title': title,
          'company': company,
          "links": f"https://stackoverflow.com/jobs/{job_id}"
      }
  def extract_jobs(last_page) :
      jobs = []
      for page in range(last_page) :
          print(f"Scrapping S0: Page: {page}")
          result = requests.get(f"{url3}&pg={page+1}")
          soup = BeautifulSoup(result.text, "html.parser")
          results = soup.find_all("div",{"class":"-job"})
          for result in results:
              job = extract_job(result)
              jobs.append(job)
      return jobs

  def get_jobs():
      last_page = get_last_page()
      jobs = extract_jobs(last_page)
      return jobs
    
  db = db + get_jobs()
  
    
    
    
  return db