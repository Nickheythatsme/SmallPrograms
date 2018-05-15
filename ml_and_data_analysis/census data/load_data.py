import numpy as np
import pandas as pd
import csv

# Headers for data
headers = [
    "age",
    "workclass",
    "fnlwgt",
    "education",
    "education-num",
    "marital-status",
    "occupation",
    "relationship",
    "race",
    "Female",
    "capital-gain",
    "capital-loss",
    "hours-per-week",
    "native-country",
    "income"]

# Load the contents of the csv file into a list
def load_contents(filename):
    lines = []
    with open('adult.test.csv','r') as fin:
        creader = csv.reader(fin)
        for line in creader:
            lines.append(line)
    return lines

# Remove any empty lines, make income true/false
def clean_contents(lines):
    # Remove the first row
    lines.pop(0)

    # Remove any rows with no data (last row)
    for i,line in enumerate(lines):
        if len(line) == 0:
            lines.pop(i)

    # Change income to less than or equal to 50K (True/false)
    for line in lines:
        # Change age to int
        line[0] = int(line[0])

        # Change education-num to int
        line[4] = int(line[4])

        # Change sex to Female true/false
        line[9] = line[9] == ' Female'

        # Change capital gain/loss
        line[10] = int(line[10])
        line[11] = int(line[11])

        # Change number of hours per week to int
        line[12] = int(line[12])

        # Change income to True/false
        line[14] = line[14] == ' <=50K.'
    return lines

# Make a pandas data field from data
def make_df(data):
    df = pd.DataFrame(data, columns=headers)
    return df

def get_data(filename):
    contents = load_contents(filename)
    contents = clean_contents(contents)
    return make_df(contents)

adult_data = get_data('./adult.data.csv')
adult_test = get_data('./adult.test.csv')


if __name__ == "__main__":
    for i in adult_test:
        print("Name: {}\tType: {}".format(i, type(adult_test[i][0])))
