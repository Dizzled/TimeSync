#!/usr/bin/env python
import tkinter as tk
from tkinter import filedialog
from pandas import DataFrame

global df

def export(dataFile):

    exportFilePath = filedialog.asksaveasfile(defaultextension='.csv')
    dataFile.to_csv(exportFilePath, index = None, header=True)

# Function to output sensor time
def sensorTime():
    sensorTime = 0
    sensor = []
    for i in range(0, 3001):
        sensorTime += .02
        sensor.append(sensorTime)

    return sensor

# Function to output processor time
def processorTime():
    sensorStartTime = 1000
    processor = []

    for i in range(0, 3001):

        processor.append(sensorStartTime)

    return processor

def createFile():

    #Create Headers for file dataFrame
    root = tk.Tk()

    df = DataFrame(columns=['dataValidTime', 'dataReceiveTime_System'])
    df.append(sensorTime())
    canvas = tk.Canvas(root, width = 300, height = 300, bg = 'grey', relief = 'raised')
    canvas.pack()

    saveButton = tk.Button(text='Generate Simulation Data', command=export(df), bg='green', fg='white', font=('helvetica', 12, 'bold'))

    canvas.create_window(150, 150, window=saveButton)
    root.mainloop()


createFile()