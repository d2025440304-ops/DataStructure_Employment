from reportlab.lib.pagesizes import A4
from reportlab.pdfgen import canvas
from reportlab.lib import colors
from reportlab.lib.units import mm
from pypdf import PdfReader

OUT = "output/pdf/slist_app_summary.pdf"

c = canvas.Canvas(OUT, pagesize=A4)
W, H = A4

left = 18 * mm
right = W - 18 * mm
y = H - 16 * mm
line = 12

# Title
c.setFont("Helvetica-Bold", 16)
c.drawString(left, y, "App Summary: C Singly Linked List (SList)")
y -= 14
c.setStrokeColor(colors.HexColor("#666666"))
c.setLineWidth(0.7)
c.line(left, y, right, y)
y -= 14


def heading(text):
    global y
    c.setFont("Helvetica-Bold", 11.5)
    c.drawString(left, y, text)
    y -= 11


def wrapped_text(text, font="Helvetica", size=10, indent=0):
    global y
    c.setFont(font, size)
    max_w = right - (left + indent)
    words = text.split()
    cur = ""
    for w in words:
        test = (cur + " " + w).strip()
        if c.stringWidth(test, font, size) <= max_w:
            cur = test
        else:
            c.drawString(left + indent, y, cur)
            y -= line
            cur = w
    if cur:
        c.drawString(left + indent, y, cur)
        y -= line


def bullet(text):
    global y
    bullet_indent = 12
    text_indent = 22
    c.setFont("Helvetica", 10)
    c.drawString(left + bullet_indent, y, "-")
    max_w = right - (left + text_indent)
    words = text.split()
    cur = ""
    first = True
    for w in words:
        test = (cur + " " + w).strip()
        if c.stringWidth(test, "Helvetica", 10) <= max_w:
            cur = test
        else:
            c.drawString(left + text_indent, y, cur)
            y -= line
            cur = w
            first = False
    if cur:
        c.drawString(left + text_indent, y, cur)
        y -= line

# What it is
heading("What it is")
wrapped_text(
    "A small C app that implements a singly linked list data structure with core operations "
    "for insertion, deletion, search, traversal, and destruction. The repo is code-first and "
    "uses a simple console test driver instead of a packaged product interface."
)
y -= 4

# Who it's for
heading("Who it is for")
wrapped_text("Not found in repo. Likely primary persona: C learners and interview prep practitioners working on data structures.")
y -= 4

# What it does
heading("What it does")
bullets = [
    "Defines list node model and public API in SList.h (SLTNode, SLTDataType, operation prototypes).",
    "Supports tail/head insertion (SLTPush_Back, SLTPush_Front).",
    "Supports tail/head deletion (SLTPop_Back, SLTPop_Front).",
    "Supports value search and position-based updates (SLTFind, SLTInsert, SLTInsertAfter).",
    "Supports node deletion at and after a position (SLTErase, SLTEraseAfter).",
    "Supports full teardown to free memory (SLDestroy).",
    "Includes a console test flow in test.c that builds a list and prints it to stdout.",
]
for b in bullets:
    bullet(b)
y -= 3

# How it works
heading("How it works (repo-evidence architecture)")
bullet("Component 1: SList.h - shared data model and function declarations.")
bullet("Component 2: SList.c - linked-list implementation plus malloc/free lifecycle handling.")
bullet("Component 3: test.c - entry point; calls operations in sequence to exercise behavior.")
bullet("Data flow: main() -> SLTTest02() -> list mutations in SList.c -> SLTPrint() -> terminal output.")
bullet("External services, persistence layer, or IPC: Not found in repo.")
y -= 3

# How to run
heading("How to run (minimal)")
bullet("From repo root, compile: gcc test.c SList.c -o slist")
bullet("Run: ./slist")
bullet("Expected output pattern: integer chain ending with NULL (for example, 1->1->2->...->NULL).")
bullet("Build system config files (Makefile/CMake) and dependency manifest: Not found in repo.")

c.save()

# Sanity checks
reader = PdfReader(OUT)
print(f"Generated: {OUT}")
print(f"Pages: {len(reader.pages)}")
text = reader.pages[0].extract_text() or ""
print("Contains title:", "App Summary: C Singly Linked List (SList)" in text)
