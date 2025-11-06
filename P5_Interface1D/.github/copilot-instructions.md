<!-- .github/copilot-instructions.md
     Short, actionable guidance for AI coding agents working on this p5.js project.
-->

# Copilot instructions — P5_Interface1D

Purpose: give an AI agent the minimal, concrete knowledge to make safe, useful edits in this p5.js game.

Key facts (high level)
- This is a small p5.js game composed of plain JS files loaded from `index.html` (no bundler, no modules).
- p5 is included from CDN (v1.2.0). All runtime helpers like `createCanvas`, `color`, and `random` are p5 globals.
- Global instances created in `setup()`: `display`, `playerOne`, `playerTwo`, `target`, `controller`, `collisionAnimation`, `score`.

How to run locally (quick)
- Open `index.html` in a browser. For a dev server (recommended), from the project directory run a simple HTTP server and open `http://localhost:8000` (e.g., `python3 -m http.server 8000`).

Big-picture architecture
- `sketch.js` is the entrypoint: defines canvas size, global variables, `setup()` and `draw()`.
- `Controller` (in `controller.js`) is the game state machine. States: `PLAY`, `COLLISION`, `SCORE`.
- `Display` (in `display.js`) is a buffer abstraction. All objects write to the display buffer via `setPixel()` / `setAllPixels()`; `Display.show()` is the only code that draws to the canvas.
- `Player` (in `player.js`) holds position, color and movement logic (`move()` loops around edges).
- `Animation` (in `animation.js`) precomputes frames into `animation[numberOfFrames][pixels]`. Controller accesses `collisionAnimation.animation[...]` directly when showing frames.

Important code conventions & patterns
- Single global namespace: avoid introducing ES modules or renaming global variables. Code relies on globals like `displaySize` and `playerOne`.
- Buffer-first rendering: update display buffer, then call `display.show()` in `draw()`. Prefer touching the buffer instead of drawing directly elsewhere.
- State transitions happen in `Controller.update()`. To change game flow, modify/extend that switch statement.
- Key bindings happen via `keyPressed()` in `controller.js` (A/D for playerOne, J/L for playerTwo, R to reset).
- Colors are p5 `color()` objects; do not treat them as plain arrays/serializable values.

Examples (concrete edits)
- Add a new player: follow `playerOne` pattern in `setup()`; update `controller.update()` to render that player via `display.setPixel(newPlayer.position, newPlayer.playerColor)`.
- Change display resolution: modify `displaySize` and `pixelSize` in `sketch.js`; `createCanvas()` already uses those globals.
- Change collision animation length: edit `animation.js` (`this.numberOfFrames`, `this.pixels`) and recompute frames there.

Debugging tips
- Use browser DevTools console (add `console.log(...)` in `controller.update()` or `keyPressed()` or `Display.show()`).
- If edits don't appear, ensure `index.html` loads scripts in this order: p5, `player.js`, `controller.js`, `display.js`, `animation.js`, `sketch.js` (see `index.html`).
- If p5 globals like `createCanvas` or `color` are undefined, confirm the CDN script tag for p5 is present and loaded before other scripts.

Notable gotchas
- The project uses direct reads of `collisionAnimation.animation[...]` from `controller.js` (so `animation.animation` is treated as public). If you refactor `Animation`, preserve compatible API or update `controller.js` accordingly.
- Many values are globals (e.g., `displaySize`, `playerOne`). Refactoring into modules requires updating `index.html` load order and `setup()` initializations.
- `Animation.grabPixel()` expects `currentFrameCount` to be set by `currentFrame()` first; controller currently loops the animation using `currentFrame()` then reads full frame by indexing `animation[frame]`.

Where to look for changes
- Game flow and states: `controller.js`
- Rendering and pixel buffer: `display.js`
- Player behavior and inputs: `player.js` and `controller.js` (`keyPressed`)
- Startup and global config: `sketch.js` (top-level `displaySize`, `pixelSize`, `score`)
- Animation frames: `animation.js`

If you edit files, prefer small, visible changes and test in the browser. Ask the user about any intended refactor that touches globals or changes script load order.

End of instructions — ask what part you'd like to modify next.
