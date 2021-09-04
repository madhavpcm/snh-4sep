from PyQt5.QtCore import *
from PyQt5.QtGui import *
from PyQt5.QtWidgets import *
from github import Github
# The fondamental for working with python
import sys,signal
import requests
import os

token = os.environ.get('GITHUB_TOKEN')
from mainwindow import Ui_MainWindow
g=Github("madhavpcm",token)
class MainWindow ( QMainWindow , Ui_MainWindow):
    # Create settings for the software
    version = 'Your version'

    def __init__ ( self, parent = None ):
        QMainWindow.__init__( self, parent )
        # Load the ui generated with makepyqt5.sh
        super().__init__()
#        self.ui = Ui_MainWindow()
        self.setupUi( self )
        self.show()
        self.acceptButton.clicked.connect(self.acceptButtonClicked)
        # Set the MainWindow Title
        self.setWindowTitle('gitPortFolio' + self.version)
        # When the software are closed on console the software are closed
        signal.signal(signal.SIGINT, signal.SIG_DFL)
        # Show the form
    @pyqtSlot()
    def acceptButtonClicked(self):
        try:
            user=g.search_users(self.input.text()+"in:login")
            print(user.name)
        except 404 :
            errmsg = QMessageBox()
            errmsg.setIcon(QMessageBox.Warning)
            errmsg.setText("404 not found")
            errmsg.setWindowTitle("id error")
            errmsg.exec_()
            return
        

if __name__ == "__main__":# Start the software5b
    app = QApplication(sys.argv)
    MainWindow_ = QMainWindow()
    ui = MainWindow()
    ui.setupUi(MainWindow_)
    ui.show()
    # Add the close feature at the program with the X
    sys.exit(app.exec_())
    
# Execute the software