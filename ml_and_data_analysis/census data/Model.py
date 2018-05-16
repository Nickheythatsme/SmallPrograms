
# coding: utf-8

# In[1]:


import numpy as np
import pandas as pd
from load_data import adult_test as test_df
from load_data import adult_data as train_df


# In[2]:


import tensorflow as tf


# In[3]:


test_df.head()


# In[4]:


# Training input on the whole training set with no limit on training epochs.
train_input_fn = tf.estimator.inputs.pandas_input_fn(
    train_df, train_df["income"], num_epochs=None, shuffle=True)

# Prediction on the whole training set.
predict_train_input_fn = tf.estimator.inputs.pandas_input_fn(
    train_df, train_df["income"], shuffle=False)

# Prediction on the test set.
predict_test_input_fn = tf.estimator.inputs.pandas_input_fn(
    test_df, test_df["income"], shuffle=False)


# In[7]:


# Make feature columns
feature_cols = [
    # Education 
    tf.feature_column.numeric_column(key="education-num", dtype=tf.uint16),
    tf.feature_column.numeric_column(key="income", dtype=tf.bool),
    tf.feature_column.numeric_column(key="age", dtype=tf.uint16)
]


estimator = tf.estimator.DNNClassifier(
    hidden_units=[500, 100],
    feature_columns=feature_cols,
    n_classes=2,
    optimizer=tf.train.AdagradOptimizer(learning_rate=0.003))


# In[8]:


# Training for 1,000 steps means 128,000 training examples with the default
# batch size. This is roughly equivalent to 5 epochs since the training dataset
# contains 25,000 examples.
estimator.train(input_fn=train_input_fn, steps=1000)