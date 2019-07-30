'''

Modul pentru consola
Consola va apela service ul

'''

from domain.entitate_telefon import telefon


class consola:
    
    def __init__(self, service):
        '''
        Consola apeleaza serviceul
        '''
        self.service = service
        
    def printUi(self):
        '''
        Afisarile din meniu
        '''
        
        print("[1] -> pentru a vedea toate telefoanele")
        print("[2] -> afisarea telefoanelor care contin un anumit sir de caractere, ordonate descrescator dupa model")
        print("[3] -> suma preturilor pentru caracteristica")
        print("[4] -> exit")

    def afisezTelefoanele(self):
        '''
        Voi apela service ul -> repository pentru a lua telefoanele si le voi printa
        '''
        toateTelefoanele = self.service.toateTelefoanele()
        for Telefon in toateTelefoanele:
            print(Telefon.getId() + "\t" + Telefon.getNumeModel() +"\t" + Telefon.getCaracteristici() + "\t" +Telefon.getPret())
            
    
    
    def cautTelefoane(self):
        '''
        Introduc sirul de cautat
        le caut in service ( luate de la repository)
        daca nu am gasit afisez ca nu e niciun telefon corespunzator
        daca este , le sortez si afisez telefoanele
        '''
        sirDeCautat = input("sirul de cautat >> ")
        telefoaneCautate = self.service.cautTelefoane(sirDeCautat)
        if len (telefoaneCautate) == 0:
            print("Nu este niciun telefon corespunzator")
        
        telefoaneCautate = self.service.sortezDupaModel(telefoaneCautate)
        
        for Telefon in telefoaneCautate:
            print(Telefon.getId() + "\t" + Telefon.getNumeModel() +"\t" + Telefon.getCaracteristici() + "\t" +Telefon.getPret())
    
    
    def pretCaracteristici(self):
        '''
        voi lua o lista cu caracteristicile telefoanelor
        voi cauta cu functia de la 1) 
        si voi aduna pretul
        '''
        
        caracteristici = self.service.iauCaracteristici()
        for caracteristica in caracteristici:
            telefoaneCautate = self.service.cautTelefoane(caracteristica)
            for Telefon in telefoaneCautate:
                pret = int(Telefon.getPret())
                caracteristici[caracteristica] += pret
        
        for caracteristica in caracteristici:
            print(caracteristica + ":\t", caracteristici[caracteristica])
        
    
    def showUi(self):
        
        while True:
            self.printUi()
            try:
                comanda = int(input())
            except ValueError as ex:
                print("Comanda nu e buna")  

            if comanda == 1:
                self.afisezTelefoanele()

            if comanda == 2:
                self.cautTelefoane()

            if comanda == 3:
                self.pretCaracteristici()

            if comanda == 4:
                return 





