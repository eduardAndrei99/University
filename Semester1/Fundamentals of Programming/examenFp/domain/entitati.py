'''
Created on 20 feb. 2019

@author: Edy
'''

class Traducere(object):
    '''
    clasa traducere
    '''


    def __init__(self, limbaSursa, cuvant, limbaDestinatie, traducereCuvant):
        '''
        Constructor
        '''
        self.limbaSursa = limbaSursa
        self.cuvant = cuvant
        self.limbaDestinatie = limbaDestinatie
        self.traducereCuvant = traducereCuvant

    
    def getLimbaSursa(self):
        '''
        get pentru limbaSursa
        '''
        return self.limbaSursa

    
    def getCuvant(self):
        '''
        get cuvant
        '''
        return self.cuvant

    
    def getLimbaDestinatie(self):
        '''
        get pentru limba destinatie
        '''
        return self.limbaDestinatie

    
    def getTraducereCuvant(self):
        '''
        get pentru traducere
        '''
        return self.traducereCuvant
    
    def __str__(self):
        text = ""
        text += self.getLimbaSursa()
        text += " "
        text += self.getCuvant()
        text += " "
        text += self.getLimbaDestinatie()
        text += " "
        text += self.getTraducereCuvant()
        text += "  "
        return text
    
def testTraducere():
    '''
    functie ce testeaza clasa Traducere
    '''
    traducere1 = Traducere("En","cat","Ro","pisica")
    assert traducere1.getLimbaSursa() == "En"
    assert traducere1.getCuvant() == "cat"
    assert traducere1.getLimbaDestinatie() == "Ro"
    assert traducere1.getTraducereCuvant() == "pisica"
    
    
testTraducere()    
    

    