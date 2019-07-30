'''
Created on 12 feb. 2019

@author: Edy
'''

from domain.validator import ValidatorJucator
from Ui.consola import Consola
from controller.service import Service
from repository import repositoryFisiere

repository = repositoryFisiere("jucatori.txt")
validator = ValidatorJucator()
service = Service(validator,repository)
consola = Consola(service)

consola.showUi()