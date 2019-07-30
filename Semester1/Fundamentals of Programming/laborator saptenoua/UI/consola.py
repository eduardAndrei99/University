'''
Created on 5 dec. 2018

@author: Edy
'''

from domain.persoana import persoana
from domain.validator import persoanaValidareExceptie, evenimentValidareExceptie
from repository.persoaneRepository import persoaneRepositoryExceptie
from repository.evenimenteRepository import evenimentRepositoryExceptie
from domain.inscriere import inscriere

class consola():
    '''
    consola
    '''


    def __init__(self, persoanaService, evenimentService, inscriereService):
        '''
        Construiesc consola cu cele 3 service uri
        '''
        self.persoanaService = persoanaService
        self.evenimentService = evenimentService
        self.inscriereService = inscriereService
        
        
    def printUi(self):
        '''
        Functie ce imi afiseaza comenzile
        '''
        print ("[1] -> Adaugare persoana ") #ok
        print ("[2] -> Adaugare eveniment ") #ok
        print ("[3] -> Sterge persoana ") #ok
        print ("[4] -> Sterge eveniment") #ok
        print ("[5] -> Modifica persoana ") #ok
        print ("[6] -> Modifica eveniment ") #ok
        print ("[7] -> Afiseaza persoanele ") #ok
        print ("[8] -> Afiseaza evenimentele ") #ok
        print ("[9] -> Cauta persoana dupa id ") #ok
        print ("[10] -> Cauta eveniment dupa id ") #ok
        print ("[11] -> Inscriere persoana la eveniment ") #ok
        print ("[12] -> Afiseaza inscrierile ") #ok
        print ("[13] -> Inscrierile sortate ale unei persoane") #ok
        print ("[14] -> Persoane participante la cele mai multe evenimente ") #ok
        print ("[15] -> Primele 20 % evenimente cu cei mai multi participanti ") #ok
        print ("\n")
     
    def adaugaPersoana(self):
        '''
        Functie ce imi adauga o persoana, daca merge
        '''
        
        idPersoana = input ("Id >> ")
        nume = input("Nume >> ")
        adresa = input("Adresa >> ")
        
        try:
            self.persoanaService.crearePersoana(idPersoana, nume ,adresa)
        except persoanaValidareExceptie as ex:
            print("Nu ati introdus corect\n ")
        except persoaneRepositoryExceptie:
            print("Exista o persoana cu acest id\n ")    
     
    def afisezPersoane(self): 
        '''
        Afisarea persoanelor
        '''
        Lumea = self.persoanaService.getPersoane()
        for Persoana in Lumea:
            print(Persoana.getPersoanaId() + "\t" + Persoana.getNume() + "\t" + Persoana.getAdresa())
        print("\n\n")
        

    def adaugEveniment(self):
        '''
        Adaug eveniment in repository de evenimente
        O sa arunce exceptii in cazul in care datele introduse sunt gresite
        '''
        idEveniment = input ("Id >> ")
        data = input ("Data >> ")
        timp = input ("Timp >> ")
        descriere = input ("Descriere >> ")
        try:
            self.evenimentService.creareEveniment(idEveniment, data, timp, descriere)
        except evenimentValidareExceptie as ex:
            print(ex.args)
    
    def afisezEvenimente(self):
        '''
        Ma duc in service iar apoi in repository pentru a afisa evenimentele
        '''
        Evenimentele = self.evenimentService.getEvenimente()
        for Eveniment in Evenimentele:
            print(Eveniment.getEvenimentId() + "\t" + Eveniment.getData() + "\t" + Eveniment.getTimp() + "\t" + Eveniment.getDescriere())
        print("\n\n")
    
    
    def stergPersoana(self):
        '''
        Sterg persoana daca exista, daca nu va fi o exceptie
        '''
        idPersoana = input("Id >> ")
        try:
            self.persoanaService.stergPersoana(idPersoana)
        except persoaneRepositoryExceptie as ex:
            print("Persoana nu e ")
    
    
    def stergEveniment(self):
        '''
        Sterg un eveniment daca exista , daca nu va fi o exceptie
        '''
        idEveniment = input("Id >>")
        try:
            self.evenimentService.stergEveniment(idEveniment)
        except evenimentRepositoryExceptie as ex:
            print("Evenimentul nu e ")
    
    
    def modificaPersoana(self):
        '''
        Modific persoana daca exista, daca nu va fi o exceptie
        '''
        idPersoana = input("Id >>")
        nume = input("Nume >>")
        adresa = input("Adresa >>")
        
        try:
            self.persoanaService.modificaPersoana(idPersoana, nume, adresa)
        except persoaneRepositoryExceptie as ex:
            print("Persoana nu exista ")
    
    
    def modificaEveniment(self):
        '''
        Preconditii : sa nu fie empty
        '''
        idEveniment = input("Id >>")
        data = input("Data >>")
        timp = input("Timp >>")
        descriere = input("Descriere >>")
        try:
            self.evenimentService.modificaEveniment(idEveniment,data,timp,descriere)
        except evenimentRepositoryExceptie as ex:
            print("Evenimentul nu e ")
    

    def inscrierePersoane(self):
        idPersoana = input("IdPersoana >> ")
        idEveniment = input("IdEveniment >> ")
    
    
    def cautPersoana(self):
        idPersoana = input("Id >> ")
        persoanaCautata = self.persoanaService.cautPersoana(idPersoana)
        if persoanaCautata is None:
            print("Persoana cautata nu exista ")
        else:
            print(persoanaCautata.getPersoanaId() + "\t" + persoanaCautata.getNume() + "\t" + persoanaCautata.getAdresa())
        print("\n\n")
    

    def cautaEveniment(self):
        
        idEveniment = input("Id >>")
        evenimentCautat = self.evenimentService.cautaEveniment(idEveniment)
        if evenimentCautat is None:
            print("Evenimentul cautat nu exista ")
        else:
            print(evenimentCautat.getEvenimentId() + "\t" + evenimentCautat.getData()+"\t"+evenimentCautat.getTimp()+"\t"+evenimentCautat.getDescriere())
        print("\n\n")
        

    def inscriuPersoana(self):
        idPersoana = input("Id persoana >>")
        idEveniment = input("Id eveniment >>")
        persoanaDeInscris = self.persoanaService.cautPersoana(idPersoana)
        evenimentulDeInscris = self.evenimentService.cautaEveniment(idEveniment)
        if persoanaDeInscris is None or evenimentulDeInscris is None:
            print("Persoana sau evenimentul nu exista")
        else:
            Inscriere = self.inscriereService.creareInscriere(idPersoana, idEveniment)
            if Inscriere is None:
                print("O persoana nu poate sa se inscrie de doua ori la acelasi eveniment ")
            else:
                print("Succes!")
    

    def afisezInscrieri(self):
        '''
        Toate inscrierile este o lista
        Afisam
        '''
        toateInscrierile = self.inscriereService.getInscrieri()
        for inscriere in toateInscrierile:
            print(inscriere.getPersoanaId() + "\t" + inscriere.getEvenimentId())
    
                    
    def persoaneActive(self):
        
        listaPersoane = self.inscriereService.persoaneActive()
        print("    Id_persoana   Nume    Adresa")
        for persoana in listaPersoane:
            persoanaRef = self.persoanaService.cautPersoana(persoana)
            print("\t" + persoanaRef.getPersoanaId() + "\t" + persoanaRef.getNume()+ "\t" + persoanaRef.getAdresa())
        
        print("\n\n") 
    
    
    def afisezPrimele20(self):
        
        listaEvenimente = self.inscriereService.afisezPrimele20()
        '''
        listaEvenimente contine pe pozitiile impare evenimentul si pe cele pare numarul de persoane inscrise
        Deci trebuie un sort 
        '''
        listaEvenimenteSortate = self.inscriereService.sortezPrimele20(listaEvenimente)
        '''
        Acum trebuie sa afisez primele 20 % evenimente din lista evenimente sortate
        '''
        lungime = len(listaEvenimenteSortate)
        lungime = lungime //5 
        if lungime == 0:
            lungime = 1 
        for contor in range(0, lungime, 2):
            eveniment = self.evenimentService.cautaEveniment(listaEvenimenteSortate[contor])
            print(eveniment.getEvenimentId() + "\t" + eveniment.getDescriere())
        print("\n\n")
        
    
    
    def inscrieriSortateAlePersoanei(self):
        '''
        Daca persoana exista 
        Ii voi lua evenimentele
        Apoi voi crea o noua lista de forma:
        Eveniment, data, descriere
        Apoi sortare
        '''
        idPersoana = input("Id >> ")
        persoanaCautata = self.persoanaService.cautPersoana(idPersoana)
        if persoanaCautata is None:
            print("Persoana la care vreti sa faceti raport nu exista ")
            return
        evenimentelePersoanei = self.inscriereService.getEvenimenteUneiPersoane(idPersoana)
        
        listaDeSortat = []
        for contor in evenimentelePersoanei:
            EvenimentCautat = self.evenimentService.cautaEveniment(contor)
            listaDeSortat.append(contor)
            listaDeSortat.append(EvenimentCautat.getData())
            listaDeSortat.append(EvenimentCautat.getDescriere())
        self.inscriereService.sortezLista(listaDeSortat)
        for contor in range(0,len(listaDeSortat)):
            if contor % 3 == 0:
                print("\n")
            print(listaDeSortat[contor] + "\t")
    
    def showUi(self):
        
        while True:
            self.printUi()
            comanda = input("Introduceti comanda ")
            
            if comanda == '1':
                self.adaugaPersoana()
            if comanda == '2':
                self.adaugEveniment()
            if comanda == '3':
                self.stergPersoana()
            if comanda == '4':
                self.stergEveniment()
            if comanda == '5':
                self.modificaPersoana()
            if comanda == '6':
                self.modificaEveniment()
            if comanda == '8':
                self.afisezEvenimente()
            if comanda == '7':
                self.afisezPersoane()
            if comanda == '9':
                self.cautPersoana()
            if comanda == '10':
                self.cautaEveniment()
            if comanda == '11':
                self.inscriuPersoana()
            if comanda == '12':
                self.afisezInscrieri()
            if comanda == '13':
                self.inscrieriSortateAlePersoanei()
            if comanda == '14':
                self.persoaneActive()
            if comanda == '15':
                self.afisezPrimele20()
            
                
        
        
        
        
        
        