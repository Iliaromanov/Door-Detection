# Script to generate sample dataset before Nathaniel finishes collecting real data
import csv
import random

col_titles = ['Type']
for num in range(90):
    col_titles.append(f"Distance{str(num)}")



with open("test_data.csv", 'a') as myfile:
    wr = csv.writer(myfile)
    wr.writerow(col_titles)
    for i in range(10):
        scan = [random.randint(0,1)]
        for j in range(90):
            scan.append(random.randint(0, 300))
        wr.writerow(scan)

myfile.close()