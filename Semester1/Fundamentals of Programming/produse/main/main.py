'''
Created on 30 ian. 2019

@author: Edy
'''

from Ui.consola import Consola
from repository.repositoryFisierProdue import RepositoryProduse
from service.controler import ServiceProduse
from domain.validator import ValidatorProduse

repository = RepositoryProduse("produse.txt")
validatorProduse = ValidatorProduse()
service = ServiceProduse(repository,validatorProduse)
ui = Consola(service)
ui.showUi()