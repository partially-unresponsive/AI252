"""
Personal attempt at implementing a TUI using Textual.

Sample goal: idk. Finish lab 5 with this?
"""

from textual.app import App, ComposeResult
from textual.containers import Container, Horizontal
from textual.widgets import Button, Footer, Header, Static

QUESTION = "Do you want to learn about Textual CSS?"


class ExampleApp(App):
    CSS_PATH = "Lab5.tcss"

    def compose(self) -> ComposeResult:
        yield Header(name="Laborator 5 (Py)")
        yield Footer()
        yield Container(
            Static(QUESTION, classes="question"),
            Horizontal(
                Button("Yes", variant="success"),
                Button("No", variant="error"),
                classes="buttons",
            ),
            id="dialog",
        )


if __name__ == "__main__":
    app = ExampleApp()
    app.run()