#coding:utf-8
from Crypto.PublicKey import RSA
from Crypto.Util.number import *

def getkey():
    k = long(65537)
    p = long(open('p','r').read())
    q = long(open('q','r').read())
    n = p*q
    m = p*q+4+2*(p+q)
    d = inverse(k, (p-1)*(q-1))
    e = inverse(k, (p+1)*(q+1))
    k1 = RSA.construct((n, k, d))
    k2 = RSA.construct((m, k, e))
    return (k1, k2)

r1,r2 = getkey()
fl = bytes_to_long(open("flag", "r").read())
fl = r1.encrypt(fl,1)[0]
en = r2.encrypt(fl,0)[0]

with open("cipher", "w") as f:
    f.write("key1=%d\n\n\n"% r1.n)
    f.write("key2=%d\n\n\n"% r2.n)
    f.write("cipher=%d\n\n\n"% en)

