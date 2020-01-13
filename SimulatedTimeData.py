#!/usr/bin/env python
import tkinter as tk
from tkinter import filedialog
import pandas as pd
import random

# Export out to csv format
def export():

    exportFilePath = filedialog.asksaveasfile(defaultextension='.csv')
    df.to_csv(exportFilePath, index = None, header=True, line_terminator='\n', sep=',')

# Function to output sensor time
def sensorTime():
    list = []
    for i in range(0, 3001):
        k = i * 0.02
        list.append(k)
    df2 = pd.DataFrame({'dataValidTime':list})
    return df2

# Function to output processor time
def processorTime():
    sensorStartTime = 1000
    processor = []
    #Random Time Step Based on Min Max values for given intervals
    for i in range(0, 3001):
        sensorStartTime += random.uniform(.0001, .069321)
        processor.append(sensorStartTime)

    return processor

    return processor

# Generate csv File dataframe
def createFile():
    global df
    root = tk.Tk()
    pd.set_option('display.max_rows',3001)
    df = pd.DataFrame(columns=['dataValidTime'])

    addedSensor = sensorTime()
    addedProcessor = processorTime()

    df = df.append(addedSensor, ignore_index=True, sort=False)
    df.insert(1, 'dataReceiveTime_System', addedProcessor, True)

    canvas = tk.Canvas(root, width = 300, height = 300, bg = 'grey', relief = 'raised')
    canvas.pack()

    saveButton = tk.Button(text='Generate Simulation Data', command=export(), bg='green', fg='white', font=('helvetica', 12, 'bold'))

    canvas.create_window(150, 150, window=saveButton)
    root.mainloop()


createFile()