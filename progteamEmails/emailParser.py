import pandas

df = pandas.read_csv("google-contacts.csv")

emailsDf = pandas.read_csv("maillist.txt")

signupDf = pandas.read_csv("signup.txt")

#print(signupDf)
#print(emailsDf)

df = df.append(emailsDf, sort = True)
df = df.append(signupDf, sort = True)

df.drop_duplicates()
#print(df["E-mail Address"])
df.to_csv("listOfMembers.csv")
