# Homework 6
import re

# REGULAR EXPRESSIONS

# Write patterns for regular expressions a-d here.
# You must use a single regular expression for each item.
# For part d, also include a substitution string.

a = re.compile(r"^(?=.*qu)(?=.*zz)^[a-zA-Z]+$")

b = re.compile(r"(\(\d{3}\)( ?)|\d{3}-)\d{3}-\d{3}")

c = re.compile(r"^[^ ]*\[([1-9]\d*)+(\; *[1-9]\d*)*\][^ ]*$")

d = re.compile(r"^ *([^?:]*[^?: ]) *\? *([^?:]+?) *\: *([^?:]+)$")
subStr = r"\2 if \1 else \3"   # Place what you want to substitute (used in sub)

# TESTS
# Part a
print("----Part a tests that match:")
print(a.search("aquapizza"))
print(a.search("AquAPIzzA"))
print(a.search("quzz"))
print(a.search("zzqu"))
print(a.search("ifjiosdjfquadoajfoiszz"))
print(a.search("tacopizzaaqu"))
print(a.search("oijfizzoijafqudoodoo"))
print(a.search("nospacesherequzznospaces"))
print(a.search("zzzzzzzzzzquuuququququ"))
print(a.search("ADJFIOAJEFAquAOIDJFIAJzz"))

print("----Part a tests that do not match:")
print(a.search("aquataco"))
print(a.search("qu"))
print(a.search("zz"))
print(a.search("38qq903fjkwiwezz984"))
print(a.search(" "))
print(a.search("392949002838"))
print(a.search("4"))
print(a.search("AJFIAIFJEIOJAQUAAJDFZZ"))
# Part a

# Part b
print("----Part b tests that match:")
print(b.search("(555) 123-4567"))
print(b.search("(555)123-4567"))
print(b.search("555-123-4567"))

print("----Part b tests that do not match:")
print(b.search("(555)-123-4567"))
print(b.search("(555)  123-4567"))
print(b.search("555 123-4567"))
print(b.search("555 123 4567"))
print(b.search("(555) 123 4567"))
# Part b

# Part c
print("----Part c tests that match:")
print(c.search("[1; 4; 6; 12; 3; 70]"))
print(c.search("[1;4;6;12;3;70]"))
print(c.search("[70]"))
print(c.search("[1]"))
print(c.search("[1838928;           40;   612;1253; 323;      703743]"))
print(c.search("[1838928;40;612;1253;323;703743]"))

print("----Part c tests that do not match:")
print(c.search("[1; 4; hi; 12; 3; 70]"))
print(c.search("[]"))
print(c.search("[hello]"))
print(c.search("[1; 4; 87; 12; 3; 70;]"))
print(c.search(" [1; 4; 60; 12; 3; 70]"))
print(c.search("[1; 4; 2; 12; 3; 70] "))
print(c.search(" [1; 4; 5; 12; 3; 70] "))
print(c.search("             [1; 4; 60; 12; 3; 70]"))

# Part c

# Part d
print("----Part d tests:")
print(d.sub(subStr, "a < b ? x : 3 + y"))
print(d.sub(subStr, "a < b        ?x:                       3 + y"))
print(d.sub(subStr, "a<b?x:3+y"))
print(d.sub(subStr, "a< b?x:3 +y"))
print(d.sub(subStr, "4 ? x : 3 + y"))
print(d.sub(subStr, "a? x : b"))
print(d.sub(subStr, "    a.- ? x : b"))
print('not converted')
print(d.sub(subStr, "a < b  x  3 + y"))
print(d.sub(subStr, "a : b ? x : 3 + y"))
print(d.sub(subStr, "a:b?x:3+y"))
print(d.sub(subStr, "? < b ? x : 3 + y"))
print(d.sub(subStr, "? x : b"))
print(d.sub(subStr, " ? x : b"))
print(d.sub(subStr, " ? : "))
print(d.sub(subStr, "?:"))
print(d.sub(subStr, "? x: "))
# Part d


