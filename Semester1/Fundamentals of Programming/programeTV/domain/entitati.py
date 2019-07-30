'''
Created on 14 feb. 2019
Entintatea emisiune
@author: Edy
'''

class Emisiune(object):
    '''
    Emisiunea contine: nume, tip, durata(in ore),descriere
    '''

    def __init__(self, nume, tip, durata, descriere):
        '''
        Constructor
        Construiesc o emisiune cu acesti 4 parametri
        '''
        self.nume = nume
        self.tip = tip
        self.durata = durata
        self.descriere = descriere
    
    def getNume(self):
        '''
        get pentru nume
        '''
        return self.nume

    
    def getDurata(self):
        '''
        get pentru durata
        '''
        return self.durata

    
    def getTip(self):
        '''
        get pentru tip
        '''
        return self.tip

    
    def getDescriere(self):
        '''
        get pentru descriere
        '''
        return self.descriere
    
    def __str__(self):
        '''
        returnez un string continand specificatiile emosiunii
        pentru a fi mai usor de lucrat
        '''
        text = ""
        text += self.getNume()
        text += "  "
        text += self.getTip()
        text += "  "
        text += str(self.getDurata())
        text += "  "
        text += self.getDescriere()
        return text
    

def testEmisiune():
    '''
    testez constructorul de emisiune dar si get 
    '''
    emisiune1 = Emisiune("accesDirect","div",2,"descr")
    assert emisiune1.getNume() == "accesDirect"
    assert emisiune1.getTip() == "div"
    assert emisiune1.getDurata() == 2
    assert emisiune1.getDescriere() == "descr"

def testStr():
    emisiune1 = Emisiune("accesDirect","div",2,"descr")
    text = str(emisiune1)
    assert text == "accesDirect  div  2  descr"
 
testEmisiune()
testStr()
    
    
    
    
    
    