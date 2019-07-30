'''
Created on 5 dec. 2018

@author: Edy
'''

class persoanaValidareExceptie(Exception):
    
    def __init__(self, exceptii):
        self.exceptii = exceptii
    
    def getExceptii(self):
        return self.exceptii
    
class evenimentValidareExceptie(Exception):
    
    def __init__(self, exceptii):
        self.exceptii = exceptii
        
    def getExceptii(self):
        return self.exceptii

class persoanaValidator:
    '''
    Validarea unei persoane
    '''
    def validate(self, persoana):
        
        exceptii = []
        if persoana.getPersoanaId() == "":
            exceptii += "Id ul nu poate fi gol "
        if persoana.getNume() == "":
            exceptii += "Numele nu poate fi gol "
        if persoana.getAdresa() == "":
            exceptii += "Adresa nu poate fi goala "
        
        if len(exceptii) > 0 :
            raise persoanaValidareExceptie(exceptii)
            

class evenimentValidator:
    
    def validate(self, eveniment):
        
        exceptii = []
        if eveniment.getEvenimentId() == "":
            exceptii += "Id ul nu poate fi gol "
        if eveniment.getData() == "":
            exceptii += "Data nu poate fi gol "
        if eveniment.getTimp() == "":
            exceptii += "Timpu nu exista "
        if eveniment.getDescriere() == "":
            exceptii += "Trebuie sa fie o descriere "
        
        if len(exceptii) > 0:
            raise evenimentValidareExceptie(exceptii)



