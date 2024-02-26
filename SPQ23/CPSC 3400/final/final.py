# Homework 6
import re

# REGULAR EXPRESSIONS

# Write patterns for regular expressions a-d here.
# You must use a single regular expression for each item.
# For part d, also include a substitution string.

a = re.compile(r"[qQ][^uU]|[qQ]$")

b = re.compile(r"[qQ](?![uU])")

subStr = r"\2 if \1 else \3"   # Place what you want to substitute (used in sub)

# TESTS
# Part a
print("----Part a tests that match:")
print(a.search("aldjoiadjsojaqioafjaosidjjqiejfij"))
print(a.search("qidfjodiqiid"))

print("----Part a tests that do not match:")
print(a.search("aquataco"))
print(a.search("quqy"))
# Part a

print("")

# Part b
print("----Part a tests that match:")
print(a.search("aldjoiadjsojaqioafjaosidjjqiejfij"))
print(a.search("qidfjodiqiid"))

print("----Part a tests that do not match:")
print(a.search("aquataco"))
print(a.search("quqy"))
# Part b


