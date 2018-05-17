
# coding: utf-8

# In[3]:


import numpy as np
import pandas as pd
from load_data import adult_test as test_df
from load_data import adult_train as train_df


# In[4]:


from sklearn import metrics, preprocessing, linear_model
from sklearn.utils import shuffle
import numpy as np


# In[6]:


test_df.head()


# In[29]:


# Set seed for reproducibility
np.random.seed(1)


# In[40]:


# Transform the loaded CSV data into numpy arrays
features = [f for f in list(train_df) if "num" in f]
X = train_df[features]
Y = train_df["income"]
x_prediction = test_df[features]
X_shuf, Y_shuf = shuffle(X, Y)


# In[41]:


class_weights = {}
for f in features:
    class_weights[f] = 1
model = linear_model.LogisticRegression(n_jobs=1, class_weight=class_weights)


# In[42]:


model.fit(X_shuf, Y_shuf)

