import sys
import os
import shlex
import subprocess

read_the_docs_build = os.environ.get('READTHEDOCS', None) == 'True'

if read_the_docs_build:
    subprocess.call('doxygen', shell=True)

extensions = ['breathe']
breathe_projects = { 'Nanoshield_Termopar': 'xml' }
breathe_default_project = "Nanoshield_Termopar"
templates_path = ['_templates']
source_suffix = '.rst'
master_doc = 'index'
project = u'Nanoshield_Termopar'
copyright = u'2015, Nanoshield_Termopar'
author = u'Nanoshield_Termopar'
version = '1.0'
release = '1.0'
language = None
exclude_patterns = ['_build']
pygments_style = 'sphinx'
todo_include_todos = False
html_static_path = ['_static']
htmlhelp_basename = 'Nanoshield_Termopardoc'
latex_elements = {
}
latex_documents = [
  (master_doc, 'Nanoshield_Termopar.tex', u'Nanoshield\_Termopar Documentation',
   u'Nanoshield\_Termopar', 'manual'),
]
