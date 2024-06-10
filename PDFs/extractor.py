from pdf2image import convert_from_path
import os

# Path to the PDF file
pdf_path = "ADDS_2022_S1.pdf"

# Output directory for images
output_dir = "output_images"
os.makedirs(output_dir, exist_ok=True)

# Convert PDF pages to images
pages = convert_from_path(pdf_path, first_page=1, last_page=18, dpi=300)

# Save images and generate HTML content
html_content = '<html><head><title>PDF Pages</title></head><body>'
for i, page in enumerate(pages, start=1):
    image_path = os.path.join(output_dir, f"page_{i}.png")
    page.save(image_path, 'PNG')
    html_content += f'<h2>Page {i}</h2>'
    html_content += f'<img src="{image_path}" alt="Page {i}"><br><br>'

html_content += '</body></html>'

# Save the HTML content to a file
with open('output.html', 'w', encoding='utf-8') as f:
    f.write(html_content)

print("HTML file has been created successfully.")
