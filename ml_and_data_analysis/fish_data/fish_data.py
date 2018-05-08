import csv
import os

# Get the csv file
def get_file_contents(path):
    headers = []
    lines = []
    final_dict = {}
    with open(path, 'r') as fin:
        reader = csv.reader(fin)
        for line in reader:
            lines.append(line)
        headers = lines.pop(0)
    for i,h in enumerate(headers):
        final_dict[h] = []
        for line in lines:
            final_dict[h].append(line[i])
    return final_dict

def main():
    try:
        data = get_file_contents('oregon_fish_data.csv')
        for h in data:
            print("header: {}\tFirst 2 data: {}".format(h, data[h][0:2]))
    except Exception as e:
        print(e)
        exit(1)

main()
