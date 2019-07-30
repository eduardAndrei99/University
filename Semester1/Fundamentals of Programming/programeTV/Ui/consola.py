from repository.repository import RepoError
from utils.utils import citesteNumar
class Consola():
    
    def __init__(self, service):
        '''
        :param service: Ui comunica direct cu service
        '''
        self.service = service
        
        
    def printUi(self):
        '''
        functie ce afiseaza meniul
        '''
        print("1 -> Stergere ")
        print("2 -> Actualizare ")
        print("3 -> Program ")
        print("4 -> Blocare ")

        
    def stergEmisiune(self):
        '''
        citesc de la tastatura numele si tipul
        caut in fisier si sterg
        '''
        nume = input("Introduceti numele ")
        tip = input("Introduceti tipul ")
        try:
            self.service.stergEmisiune(nume, tip)
            print("Emisiunea", nume," a fost stearsa")
        except RepoError:
            print("Nu s a sters cu succes")
    
    def actualizezEmisiune(self):
        '''
        actualizez o emisiune
        '''
        nume = input("Introduceti numele")
        tip = input("Introduceti tipul")
        durata = citesteNumar()
        descriere = input("")
        try:
            self.service.actualizezEmisiune(nume,tip,durata,descriere)
            print("Emisiunea a fost actualizata cu succes")
        except RepoError:
            print("Nu i bines")
    
    
    
    
    def facProgram(self):
        program = self.service.facProgram()
        ora = 10
        index = 0
        for i in range (0,len(program)):
            print(ora, str(program[i]))
            index += 1
            ora += int(program[i].getDurata())
            for j in range(0,i):
                if program[i].getNume()== program[j].getNume():
                    print("*")
    

    def blochezProgram(self):
        tip = input("Introduceti tipul de blocat")
        self.service.blochezProgram(tip)
    
    
    def showUi(self):
        '''
        Functia va prelua comanda de la tastatura
        '''
        while True:
            self.printUi()
            comanda = input()
            if comanda == "1":
                self.stergEmisiune()
            if comanda == "2":
                self.actualizezEmisiune()
            if comanda == "3":
                self.facProgram()
            if comanda == "4":
                self.blochezProgram()    
                
                
            