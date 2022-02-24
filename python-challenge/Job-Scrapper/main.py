from scrapper import scrap_jobs
from flask import Flask, render_template, request, send_file
from exporter import save_files


app = Flask("Last")
db = {}

@app.route("/")
def home():
  return render_template("home.html")

@app.route("/read")
def read():
  keyword = request.args.get("word").lower()
  fromdb = db.get(keyword)
  if fromdb:
    jobs = fromdb
  else :
    jobs = scrap_jobs(keyword)
    db[keyword] = jobs
  return render_template("read.html",jobs=jobs,resultsNumber=len(jobs),searching_by=keyword)
  
@app.route("/export")
def export() :
  keyword = request.args.get('word')
  jobs = db.get(keyword)
  save_files(jobs)
  return send_file("jobs.csv")

app.run(host="0.0.0.0")