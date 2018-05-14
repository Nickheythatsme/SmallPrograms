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
    "sex",
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
        if line[14] == ' <=50K.':
            line[14] = 1
        else:
            line[14] = 0
    return lines

# Make a pandas data field from data
def make_df(data):
    return pd.DataFrame(data, columns=headers)

def clean_df(df):
    map(int, df["education-num"])

def get_data(filename):
    contents = load_contents(filename)
    contents = clean_contents(contents)
    return clean_df(make_df(contents))

adult_data = get_data('adult.data.csv')
adult_test = get_data('adult.test.csv')

