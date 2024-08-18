import requests

# Using the example query "demon", and looking at the 1st page of results.
url = "https://api.consumet.org/anime/animepahe/demon"
response = requests.get(url, params={"page": 1})
data = response.json()

print(data)
