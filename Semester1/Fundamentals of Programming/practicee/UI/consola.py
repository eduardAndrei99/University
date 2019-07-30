
from domain.entitati import Student
from domain.validator import ValidatorStudent, ExceptieStudent
from service.serviceStudent import ServiceStudent
from repository.inMemorieRepository import RepositoryExceptie

class Consola():
    
    def __init__(self, serviceStudent):
        self.serviceStudent = serviceStudent
        
    
    def printUi(self):
        print("1->adaugare")
        print("2->afisare")
        print("3->stergere")
    

    def adaugareStudent(self):
        
        id = input("id >> ")
        nume = input("nume >>")
        adresa = input ("adresa >>")
        try:
            self.serviceStudent.adaugareStudent(id,nume,adresa)
            print("Studentul a fost adaugat cu succes")
        except ExceptieStudent as ex:
            print(ex.getErori())
        except RepositoryExceptie as repoEx:
            print("Exista de 2 ori")
    
    
    def afisareStudenti(self):
        totiStudentii =  self.serviceStudent.getAllStudent()
        for st in totiStudentii:
            print(st.getNume())
            
            
    def showUi(self):
        while True:
            self.printUi()
            cmd = input()
            if cmd == "1":
                self.adaugareStudent()
            if cmd == "2":
                self.afisareStudenti()
            if cmd == "3":
                self.stergereStudent()

