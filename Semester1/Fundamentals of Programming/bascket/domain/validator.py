'''
Created on 12 feb. 2019

@author: Edy
'''
from domain.entitate import Jucator


class ExceptieJucator(Exception):
    
    def __init__(self, erori):
        '''
        :param erori:
        '''
        self.erori = erori
        
    def getErori(self):
        '''
        get pentru erori; ca sa afisam;
        '''
        return self.erori
    
    def __str__(self):
        eroare = ""
        for item in self.erori:
            eroare += str(item)
            eroare += " "
        return eroare
            

class ValidatorJucator:
    '''
    validarea unui jucator
    '''

    def validate(self, jucator):
        '''
        :param jucator: jucatorul de validat
        functia va da exceptieJucator in cazul in care avem erori
        '''
        
        posturi = ["Fundas","Extrema","Pivot"]
        erori = []
        
        if jucator.getNume() == "":
            erori.append("Numele nu poate fi gol")
        if jucator.getPrenume() =="":
            erori.append("Prenumele nu poate fi gol")
        if jucator.getInaltime() <= 0:
            erori.append("Inaltimea e mai mic ca 0")
        if jucator.getPost() not in posturi:
            erori.append("Post gresit")
        
        if len(erori) > 0:
            raise ExceptieJucator(erori)
        
        
        
        
def testValidare():
    validator = ValidatorJucator()
    jucator1=Jucator("mihai","ion",1222,"mijlocas")
    try:
        validator.validate(jucator1)
        assert False
    except ExceptieJucator as ex:
        assert len(ex.getErori()) == 1

testValidare()
        
        
        
        
        