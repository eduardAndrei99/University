'''
Created on 12 feb. 2019

@author: Edy
'''


def citesteNumar():
    while True:
        numar = input("Inaltimea >> ")
        try:
            numar = int(numar)
            return numar
        except ValueError as ve:
            print("Nu ati introdus un numar")
  
  
def golescFisier(numeFisier):
    
    file = open(numeFisier,"w")
    file.close()