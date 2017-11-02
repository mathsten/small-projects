# importer biblioteker
import pyscreenshot as ImageGrab
import time

# deklarer variabler
N = 20
total_RGB = [0, 0, 0]
average_RGB = [0, 0, 0]
count = 0

# Ta starttiden pa prosessen
time1 = time.time()

# Hent skjermbilde
if __name__ == '__main__':
    bim = ImageGrab.grab()

# loop igjennom bildet, og hent 400 pixler
for col in range(0, im.width - 1, im.width / N):
    for row in range(0, im.height - 1, im.height / N):
        pixel = im.getpixel((col, row))

        # Summer RGB verdi
        for i in range(3):
            total_RGB[i] += pixel[i]
        count += 1

# Print total RGB
print "Total RGB: ", (total_RGB)

# Gjennomsnitt
for i in range(3):
    average_RGB[i] = total_RGB[i] / count

# print Gjennomsnitt RGB
print "Gjennomsnitt RGB: ", (average_RGB)

# Regn ut og print prosesstid
time2 = time.time()
print "Tid: ", (time2 - time1)
