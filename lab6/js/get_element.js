const paragraph = document.getElementById('styled-paragraph');

function updateStyles() {
  const r = document.getElementById('r').value;
  const g = document.getElementById('g').value;
  const b = document.getElementById('b').value;
  const borderWidth = document.getElementById('borderWidth').value;

  paragraph.style.color = `rgb(${r}, ${g}, ${b})`;
  paragraph.style.borderColor = `rgb(${r}, ${g}, ${b})`;
  paragraph.style.borderWidth = `${borderWidth}px`;
}

document.getElementById('r').oninput = updateStyles;
document.getElementById('g').oninput = updateStyles;
document.getElementById('b').oninput = updateStyles;
document.getElementById('borderWidth').oninput = updateStyles;

