# -*- coding:utf8 -*-
def xor_():
    f=[0]*38
    f[0]=ord('f')
    key="b5c554f1847015d7ad5f2a891df2749df2a897"
    k=[ord(i) for i in key]
    k_=[ord(i) for i in key]
    re=[89,122,31,96,76,122,74,121,19,115,93,104,75,125,64,48,12,106,1,43,5,58,84,107,2,121,86,108,11,97,78,36,26,51,92,114,92,9]
    for i in range(len(re)-1):
        k[i+1]^=k[i]^f[i%5]^f[i%7]
        re[i+1]=re[i+1]^k_[i+1]^0x78
        f[i+1]=re[i]^k[i]^k_[i+1]^0x56^0x34
    print ''.join([chr(i) for i in f])
    pass
if __name__ == '__main__':
    xor_()
