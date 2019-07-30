'''
Created on 10 dec. 2018

@author: Edy
'''

class telefon(object):
    '''
    Clasa pentru telefoane
    '''


    def __init__(self, id, numeModel, caracteristici, pret):
        '''
        Conditii
        id ul, numele , caracteristica si pretul sa nu fie gol
        '''
        self.id = id
        self.numeModel = numeModel
        self.caracteristici = caracteristici
        self.pret = pret

    
    def getId(self):
        return self.id

    
    def getNumeModel(self):
        return self.numeModel

    
    def getCaracteristici(self):
        return self.caracteristici

    
    def getPret(self):
        return self.pret

    
def testTelefon():
    
    Telefon = telefon("87", "pixel3", "android","100")
    assert Telefon.getId() == "87"
    assert Telefon.getNumeModel() == "pixel3"
    assert Telefon.getCaracteristici() == "android"
    assert Telefon.getPret() == "100"
    
    Telefon1 = telefon("33", "iph", "ios", "1000")
    assert Telefon1.getNumeModel() == "iph"
    assert Telefon1.getId() == "33"
    assert Telefon1.getCaracteristici() == "ios"
    assert Telefon1.getPret() == "1000"
    
 
testTelefon()       
    
    