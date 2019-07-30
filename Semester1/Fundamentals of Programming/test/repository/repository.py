'''
Repository pentru telefon

'''

from domain.entitate_telefon import telefon

class repositoryTelefon():
    
    def __init__(self, numeFisier):
        '''
        '''
        self.numeFisier = numeFisier
        
    def toateTelefoanele(self):
        '''
        Voi citi si returna o lista cu telefoanele
        '''
        
        try:
            fisier = open(self.numeFisier,"r")
        except IOError:
            print("Fisierul nu exista")
            return
        
        #Tratez exceptia ca fisirul sa existe
        telefoane = []
        
        # Voi returna lista cu telefoane
        
        linie = fisier.readline().strip()
        #separ liniile prin virgula si creez telefoanele
        while linie != "":
            
            delimitator = linie.split(",")
            telefonNou = telefon(delimitator[0],delimitator[1],delimitator[2],delimitator[3])
            linie = fisier.readline().strip()
            telefoane.append(telefonNou)
            
        return telefoane
        

