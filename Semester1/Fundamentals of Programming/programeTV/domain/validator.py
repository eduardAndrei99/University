'''
Created on 14 feb. 2019
Validatorul unei emisiuni
@author: Edy
'''


class ExceptieEmisiune(Exception):
    
    def __init__(self, erori):
        '''
        :param erori: erorile ce le are o emisiune
        '''
        self.erori = erori
    
    def getErori(self):
        '''
        get pentru erori
        '''
        return self.erori
    
    def __str__(self):
        text = ""
        for eroare in self.erori:
            text += eroare
            text += "    "
        return text
    
class ValidatorEmisiune:
    '''
    validatorul verifica daca emisiunea este buna
    '''

    def validate(self, emisiune):
        '''
        :param emisiune: emisiunea de validat
        vedem daca emisiunea are probleme si raise error in caz de nu e buna
        '''
        erori =[]
        if emisiune.getNume() == "":
            erori.append("Numele nu poate fi gol")
        if emisiune.getTip() == "":
            erori.append("Tipul nu poate fi gol")
        if emisiune.getDurata() < 0:
            erori.append("Durata e un numar natural")
        if emisiune.getDescriere() == "":
            erori.append("Descrierea nu poate fi goala")
        
        if len(erori) > 0:
            raise ExceptieEmisiune(erori)
            
        
    

    