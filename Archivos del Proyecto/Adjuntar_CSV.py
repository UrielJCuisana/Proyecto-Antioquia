import csv
import serial
import tkinter as tk
import datetime
from tkinter import messagebox

# Create a tkinter window
root = tk.Tk()
root.title("Data Logger")
root.geometry("300x150")

# Create a label to display the last value stored
last_value_label = tk.Label(root, text="Last Value: None")
last_value_label.pack(pady=10)

# Create a function to stop the program
def stop_program():
    # Close the serial connection
    ser.close()
    # Close the csv file
    csv_file.close()
    # Close the tkinter window
    root.destroy()

# Create a "Stop" button
stop_button = tk.Button(root, text="Stop", command=stop_program)
stop_button.pack(pady=10)

# Set up the serial connection
ser = serial.Serial('COM6', 9600)

# Open the csv file for writing
csv_file = open('data.csv', 'w', newline='')
csv_writer = csv.writer(csv_file)
csv_writer.writerow(['time', 'temperature', 'humidity', 'pressure'])

# Start the data logging loop
while True:
    # Read the data from the serial port
    data = ser.readline().decode().strip()
    # Split the data into its components
    temperature, humidity, pressure = data.split(',')
    # Get the current time
    current_time = datetime.datetime.now().strftime('%Y-%m-%d %H:%M:%S')
    # Write the data to the csv file
    csv_writer.writerow([current_time, temperature, humidity, pressure])
    # Update the last value label
    last_value_label.config(text=f"Last Value: {current_time}, {temperature}, {humidity}, {pressure}")
    # Update the tkinter window
    root.update()
