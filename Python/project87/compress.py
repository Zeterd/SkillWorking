from bitstring import ConstBitStream, Bits, BitArray, ReadError
from math import ceil
from math import log2
import sys


def main():
    file = open(sys.argv[1], "rb")
    msg = ConstBitStream(file)

    s_in = BitArray()
    keys = {Bits(''):0}
    s_out = BitArray()
    count = 1
    n_bits = 0
    while True:
        try:
            s_in.append(msg.read(1))
        except ReadError:
            break
        
        #Se a palavra nao tiver no dicionario
        if Bits(s_in) not in keys:
            # x = yb
            y = s_in[:-1]
            b = s_in[-1:]
            
            pos = keys[Bits(y)]
            
            #log base 2 |keys|
            n_bits = ceil(log2(len(keys)))
            
            if n_bits != 0:
                prefix = Bits(uint=int(pos), length=n_bits)
            else:
                prefix = Bits('')
            
            s_out.append(Bits('0b' + str(prefix.bin) + str(b.bin)))

            keys[Bits(s_in)] = count
            count += 1
            s_in.clear()

    #Add padding: 00000 10101
    #Numero de zeros é o tamanho dos bits extra para depois no descompressor saber
    if s_in[:1].bin == Bits(1):
        z = Bits('0b'+'0'*len(s_in))
    else:
        z = Bits('0b'+'1'*len(s_in))

    s_in.reverse()
    s_out.reverse()
    
    s_out.append(s_in)
    s_out.append(z)

    s_out.reverse()

    with open(sys.argv[2], 'wb') as f_out:
        s_out.tofile(f_out)

    file.close()

if __name__ == "__main__":
    main()