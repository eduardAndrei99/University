'''
Created on 14 feb. 2019

@author: Edy
'''

def stergFisier(numeFisier):
    f = open(numeFisier,"w")
    f.close()
    
    
def citesteNumar():
    while True:
        numar = input(">>")
        try:
            numar = int(numar)
            return numar   
        except ValueError as ve:
            print("Nu i binie")