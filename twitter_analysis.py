#!/usr/bin/env python
# coding=utf-8

import tweepy
from textblob import TextBlob
import csv

consumer_key = 'OqriG8mBO5qw4mQd8mLYCR6QG'
consumer_secret = 'DLjdp656W2CF1F6YgGNt0HqHumI42pjZDOYan0zTGhIH0y51jb'

access_token = '21324391-F5umrr9f8DSASftbuLSNA6o8sDgqMTFY1KPrHaZ1r'
access_token_secret = 'prln9lorsd0PW6bheopasUtPxAntmVCj5X8XrS53SvjUg'

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
for status in tweepy.Cursor(api.user_timeline, id='OlavSakseid').items(20):
    print(status.text)
    analysis = TextBlob(status.text)
    print(analysis)
    # writeCSV.writerow([encoded_string])

'''
OlavSakseid
for tweet in public_tweets:
    #print(tweet.text)
    analysis = TextBlob(tweet.text)
    test = print(tweet.screen_name)
    writeCSV.writerow([test]);
'''
