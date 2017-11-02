#!/usr/bin/env python
# coding=utf-8

import tweepy
from textblob import TextBlob
import csv

consumer_key = 'CONSUMER_KEY'
consumer_secret = 'CONSUMER_SECRET'

access_token = 'ACCESS_TOKEN'
access_token_secret = 'ACCCESS_TOKEN_SECRET'

# Setter opp forbindelse med twitter
auth = tweepy.OAuthHandler(consumer_key, consumer_secret)
auth.set_access_token(access_token, access_token_secret)
api = tweepy.API(auth)

# search_word = input("Hvilket ord vil du søke etter? ")
# public_tweets = api.search(search_word, count=100)

'''
with open('twitter_analyse.csv', 'w', newline='') as csvfile:
    writeCSV = csv.writer(csvfile, delimiter=',')

    for tweet in public_tweets:
        try:
            writeCSV.writerow([tweet.text])
        except Exception as e:
            print(e)
'''

# Åpner CSV fil
# csvfile = open('twitter_analyse.csv', 'w', newline='')
# writeCSV = csv.writer(csvfile, delimiter=',')

# search_word = input("Hvilket ord vil du søke etter? ")
# public_tweets = api.search(search_word, count = 100)

# Only iterate through the first 20 statuses
for status in tweepy.Cursor(api.user_timeline, id='username').items(20):
    print(status.text)
    analysis = TextBlob(status.text)
    print(analysis)
    # writeCSV.writerow([encoded_string])

'''
Username
for tweet in public_tweets:
    #print(tweet.text)
    analysis = TextBlob(tweet.text)
    test = print(tweet.screen_name)
    writeCSV.writerow([test]);
'''
