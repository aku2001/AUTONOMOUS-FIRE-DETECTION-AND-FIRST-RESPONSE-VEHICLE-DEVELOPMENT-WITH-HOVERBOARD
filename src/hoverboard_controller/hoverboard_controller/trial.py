from PIL import Image

def map_value_to_color(value):
    if value < 0:
        # Map values from 0 to -128 to light gray
        normalized_value = int((value + 128) * 255 / 128)
        return (normalized_value, normalized_value, normalized_value)
    elif value <= 20:
        # Dark blue for values 1-20
        return (0, 0, 128 + int(value * 7))
    elif value <= 40:
        # Blue for values 21-40
        return (0, 0, 255 - int(value * 7))
    elif value <= 60:
        # Pink for values 41-60
        return (255, 192 - int(value * 7), 203)
    elif value <= 80:
        # Light red for values 61-80
        return (255, 128 + int(value * 7), 128)
    elif value <= 100:
        # Dark red for values 81-100
        return (255, 0, 0)
    else:
        # Black for values 101 and above
        return (0, 0, 0)

def convert_list_to_image(number_list, block_size):
    width = len(number_list) * block_size
    height = block_size
    img = Image.new("RGB", (width, height), color="white")
    pixels = img.load()

    for i, value in enumerate(number_list):
        color = map_value_to_color(value)
        for x in range(i * block_size, (i + 1) * block_size):
            for y in range(height):
                pixels[x, y] = color

    return img

# Example usage:
number_list = [0, 64, 127, -64, -128, 0, 32, -32, 16, -16]
block_size = 20
image = convert_list_to_image(number_list, block_size)
image.show()  # Display the image
image.save("output_image.png")  # Save the image to a file