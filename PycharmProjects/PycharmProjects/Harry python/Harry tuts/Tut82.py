import json

data = '{"var1":"harry","var2":"56"}'
print(data)

parsed = json.loads(data)
print(parsed['var1'])
print(type(parsed))

### json.loads-kisi bhi json file ke object ko dictionary ke form me convert kar deta hai
data2 = {
    "channel_name":"code with harry",
    "cars":['bmw','audi8','ferrari'],
    "fridge":('roti',540)
}

jscomp = json.dumps(data2)
print(jscomp)

###
# 1) json.loads() - It is used to convert a json string to an dictionary
# 2) json.dump() - It is used to convert a dictionary to a json string
# 3) json.load() - It is used to read a file which contains an json object