'''
Service ul pentru telefon
Va comunica cu repository ul
'''



class serviceTelefon():
    
    def __init__(self, repository):
        self.repository = repository
        
    def toateTelefoanele(self):
        return self.repository.toateTelefoanele()    
    
    def cautTelefoane(self,sirDeCautat):
        '''
        voi obtine telefoanele prin get ul din repo
        si voi cauta 
        '''
        toateTelefoanele = self.toateTelefoanele()
        telefoaneCautate = []
        for Telefon in toateTelefoanele:
            if sirDeCautat in Telefon.getCaracteristici() or sirDeCautat in Telefon.getNumeModel():
                telefoaneCautate.append(Telefon)
        
        return telefoaneCautate
                
    def sortezDupaModel(self, telefoaneCautate):
        '''
        Voi folosi sortare metoda selectiei -> complexitate 0 ( n^2)
        '''
        '''
        i si j -> 2 contori pentru a putea face sortarea
        '''
        
        for i in range(0,len(telefoaneCautate)-1):
            for j in range(i+1,len(telefoaneCautate)):
                if telefoaneCautate[i].getNumeModel() < telefoaneCautate[j].getNumeModel():
                    telefoaneCautate[i], telefoaneCautate[j] = telefoaneCautate[j],telefoaneCautate[i]
        
        return telefoaneCautate
    
    def iauCaracteristici(self):
        
        '''
        In toate telefoanele voi lua caracteristicile dupa splitul spacebar
        '''
        
        toateTelefoanele = self.toateTelefoanele()
        listaCaracteristici = {}
        for Telefon in toateTelefoanele:
            Caracteristici = Telefon.getCaracteristici()
            delimitator = Caracteristici.split(" ")
            for index in range(0,len(delimitator)):
                listaCaracteristici[delimitator[index]] = 0
        
        return listaCaracteristici
        
        
        
        
    
    
    