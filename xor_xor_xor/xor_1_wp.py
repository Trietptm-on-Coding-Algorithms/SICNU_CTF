# -*- coding:utf8 -*-
def foo():
    a=[0]*19
    key="a7shw9o10e63nfi19dk"
    k=[ord(i) for i in key]
    e=[71,100,24,51,16,97,81,59,53,94,99,100,29,116,25,77,96,27,105]
    a[0]=ord('H')
    for i in range(len(e)-1):
        k[i+1]^=k[i]^a[i%7]^a[i%9]
        a[i+1]=0x53^e[i]^k[i]
    print ''.join([chr(i) for i in a])
    pass
if __name__ == '__main__':
    foo()
    print 'ok'