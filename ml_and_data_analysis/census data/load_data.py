import numpy as np
import pandas as pd
import csv

# Headers for data
headers = [
    "num_age",
    "workclass",
    "fnlwgt",
    "education",
    "num_education",
    "marital-status",
    "occupation",
    "relationship",
    "race",
    "num_Female",
    "num_capital-gain",
    "num_capital-loss",
    "num_hours-per-week",
    "native-country",
    "income"]

def income_test(x):
    if x == ' >50K.':
        return 1
    else:
        return 0

def is_female(x):
    if x == ' Female':
        return 1
    else:
        return 0

# Training data
adult_train = pd.read_csv('./adult.data.csv', names=headers)
adult_train = adult_train.drop(adult_train.index[[0,1]])
adult_train["income"] = adult_train["income"].apply(income_test)
adult_train["num_Female"] = adult_train["num_Female"].apply(is_female)

# Testing data
adult_test = pd.read_csv('./adult.test.csv', names=headers)
adult_test = adult_test.drop(adult_test.index[[0,1]])
adult_test["income"] = adult_test["income"].apply(income_test)
adult_test["num_Female"] = adult_test["num_Female"].apply(is_female)



if __name__ == "__main__":
    print("Adult test data:\n" + str(adult_test.head()))
