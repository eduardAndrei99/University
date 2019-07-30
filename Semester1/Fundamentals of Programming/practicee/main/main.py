"""
main ul 
aici voi crea si imbina aplicatia
"""

from domain.validator import ValidatorStudent
from UI.consola import Consola
from service.serviceStudent import ServiceStudent
from repository.inMemorieRepository import inMemorieRepository
from repository.fisiereRepository import RepositoryFisiere

#repositoryMemorie = inMemorieRepository()
repositoryFisiere = RepositoryFisiere("studenti.txt")
validatorStudent = ValidatorStudent()
serviceStudent = ServiceStudent(repositoryFisiere, validatorStudent)
ui = Consola(serviceStudent)

ui.showUi()






