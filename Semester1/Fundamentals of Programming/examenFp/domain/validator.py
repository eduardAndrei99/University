'''
Created on 20 feb. 2019

@author: Edy
'''
from domain.entitati import Traducere


class ExceptieTraducere(Exception):
    
    def __init__(self, erori):
        self.erori = erori
    
    def getErori(self):
        return self.erori
    
    def __str__(self):
        for eroare in self.erori:
            print(eroare)
        print()

class ValidatorTraducere:
    '''
    validator pentru traduceri
    '''
    def validate(self, traducere):
        '''
        :param traducere: traducerea pe care vrem sa o validam
        '''
        erori = []
        limbi = ["En","Ro","Fr"]
        if traducere.getLimbaSursa() == traducere.getLimbaDestinatie():
            erori.append("Limba sursa si limba destinatie sunt egale")
        if traducere.getLimbaDestinatie() not in limbi:
            erori.append("Limba destinatie nu e buna")
        if traducere.getLimbaSursa() not in limbi:
            erori.append("Limba sursa nu e buna")
        if traducere.getCuvant() =="":
            erori.append("Cuvantul este gol")
        if traducere.getTraducereCuvant() == "":
            erori.append("Cuvantul tradus este gol")
        if len(erori) > 0:
            raise ExceptieTraducere(erori)
        
def testValidare():
    '''
    test pentru validator
    '''
    validator = ValidatorTraducere()
    traducere1 = Traducere("En","cat","Ro","pisica")
    
    try:
        validator.validate(traducere1)
        assert True
    except ExceptieTraducere:
        assert False
        
    traducere2 = Traducere("Engl","","Ro","pisica")
    try:
        validator.validate(traducere2)
        assert False
    except ExceptieTraducere:
        assert True
        
        
testValidare()
    
    
            
        
        
