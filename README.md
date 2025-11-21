<!DOCTYPE html>


<h1>Oxygen/Vacuum Pressure Monitoring System</h1>
<div class="center">
    A professional embedded system for monitoring pressure levels with LCD display and alarm system
</div>

<h2 class="emoji">📋 Table of Contents</h2>
<ul>
    <li>Overview</li>
    <li>Features</li>
    <li>System Architecture</li>
    <li>Hardware Requirements</li>
    <li>Software Requirements</li>
    <li>Installation</li>
    <li>Usage</li>
    <li>Code Structure</li>
    <li>Configuration</li>
    <li>API Documentation</li>
    <li>Troubleshooting</li>
    <li>Contributing</li>
    <li>License</li>
</ul>

<h2 class="emoji">🚀 Overview</h2>
<p>The Oxygen/Vacuum Pressure Monitoring System is a robust embedded application designed for real-time monitoring of four different pressure levels. The system provides visual feedback through an LCD display, audible alerts via a buzzer, and visual indicators using LEDs.</p>
<ul>
    <li>Real-time pressure monitoring for 4 different systems</li>
    <li>LCD status display with "NORMAL" and "LOW" indicators</li>
    <li>Audible alarm system with mute functionality</li>
    <li>Visual LED indicators for system status</li>
    <li>Timer-based blinking for alert conditions</li>
</ul>

<h2 class="emoji">✨ Features</h2>
<h3>🔍 Monitoring Capabilities</h3>
<ul>
    <li>OXYGEN pressure level monitoring</li>
    <li>VACUUM pressure level monitoring</li>
    <li>AIR_4_BAR pressure level monitoring</li>
    <li>AIR_7_BAR pressure level monitoring</li>
</ul>

<h3>🎛️ User Interface</h3>
<ul>
    <li>4-line LCD display for comprehensive status overview</li>
    <li>Buzzer alarm with intelligent mute functionality</li>
    <li>LED indicators for visual status feedback</li>
    <li>Blinking alert for abnormal conditions</li>
</ul>

<h3>⚡ Technical Features</h3>
<ul>
    <li>Timer1 interrupt for precise timing (1-second intervals)</li>
    <li>External interrupt support (commented but available)</li>
    <li>Modular code architecture for easy maintenance</li>
    <li>Professional error handling with status codes</li>
</ul>

<h2 class="emoji">🏗️ System Architecture</h2>
<h3>Software Architecture</h3>
<pre>
Project Root/
├── APP/
│   ├── APP.c          # Main application
│   └── APP.h          # Application headers
├── HAL/
│   └── LCD/
│       ├── LCD_int.h
│       ├── LCD_prog.c
│       ├── LCD_private.h
│       └── LCD_config.h
├── MCAL/
│   ├── DIO/
│   │   ├── DIO_int.h
│   │   ├── DIO_prog.c
│   │   ├── DIO_private.h
│   │   └── DIO_config.h
│   ├── TIMER/
│   │   ├── TIMER_int.h
│   │   ├── TIMER_prog.c
│   │   └── TIMER_private.h
│   └── EXTI/
│       ├── EXTI_int.h
│       ├── EXTI_prog.c
│       └── EXTI_private.h
└── LIB/
    ├── StdTypes.h
    └── errorStatuse.h
</pre>

<h2 class="emoji">🔧 Hardware Requirements</h2>
<h3>Microcontroller</h3>
<ul>
    <li>PIC16F877A Microcontroller</li>
    <li>4MHz Crystal Oscillator</li>
    <li>Power Supply: 5V DC</li>
</ul>

<h3>Peripheral Components</h3>
<table>
    <thead>
        <tr>
            <th>Component</th>
            <th>Quantity</th>
            <th>Purpose</th>
        </tr>
    </thead>
    <tbody>
        <tr>
            <td>20x4 LCD Display</td>
            <td>1</td>
            <td>Status display</td>
        </tr>
        <tr>
            <td>Pressure Sensors</td>
            <td>4</td>
            <td>Level monitoring</td>
        </tr>
        <tr>
            <td>Buzzer</td>
            <td>1</td>
            <td>Audible alerts</td>
        </tr>
        <tr>
            <td>LEDs</td>
            <td>2</td>
            <td>Visual indicators</td>
        </tr>
        <tr>
            <td>Push Button</td>
            <td>1</td>
            <td>Mute function</td>
        </tr>
        <tr>
            <td>Resistors</td>
            <td>As needed</td>
            <td>Current limiting</td>
        </tr>
    </tbody>
</table>

<h3>Pin Configuration</h3>
<table>
    <thead>
        <tr>
            <th>Port</th>
            <th>Pin</th>
            <th>Function</th>
            <th>Direction</th>
        </tr>
    </thead>
    <tbody>
        <tr><td>PORTA</td><td>0</td><td>LCD RS</td><td>Output</td></tr>
        <tr><td>PORTA</td><td>1</td><td>LCD EN</td><td>Output</td></tr>
        <tr><td>PORTA</td><td>2</td><td>Level 0 Sensor</td><td>Input</td></tr>
        <tr><td>PORTA</td><td>3</td><td>Level 1 Sensor</td><td>Input</td></tr>
        <tr><td>PORTA</td><td>4</td><td>Level 2 Sensor</td><td>Input</td></tr>
        <tr><td>PORTA</td><td>7</td><td>Level 3 Sensor</td><td>Input</td></tr>
        <tr><td>PORTB</td><td>0</td><td>Mute Button</td><td>Input</td></tr>
        <tr><td>PORTB</td><td>1</td><td>Blink LED</td><td>Output</td></tr>
        <tr><td>PORTB</td><td>2</td><td>Status LED</td><td>Output</td></tr>
        <tr><td>PORTB</td><td>3</td><td>Buzzer</td><td>Output</td></tr>
        <tr><td>PORTB</td><td>4-7</td><td>LCD Data (DB4-DB7)</td><td>Output</td></tr>
    </tbody>
</table>

<h2 class="emoji">💻 Software Requirements</h2>
<ul>
    <li>MPLAB X IDE v5.50 or later</li>
    <li>XC8 Compiler v2.32 or later</li>
    <li>PICKit Programmer for flashing</li>
    <li>Standard C Libraries</li>
    <li>PIC16F877A Header Files</li>
</ul>

<h2 class="emoji">📥 Installation</h2>
<ol>
    <li>Clone the repository
        <pre>git clone https://github.com/islamnagi/pressure-monitoring-system.git
cd pressure-monitoring-system</pre>
    </li>
    <li>Setup development environment:
        <ul>
            <li>Install MPLAB X IDE</li>
            <li>Install XC8 Compiler</li>
            <li>Configure PICKit programmer</li>
            <li>Open project in MPLAB X</li>
        </ul>
    </li>
    <li>Hardware setup: Connect all components according to pin configuration table.</li>
    <li>Build and flash the project using MPLAB X.</li>
</ol>

<h2 class="emoji">🎮 Usage</h2>
<p><strong>Normal Operation:</strong></p>
<ul>
    <li>Power on: System initializes and displays "Welcome" message</li>
    <li>LCD shows all pressure levels as "NORMAL"</li>
    <li>System continuously checks all sensor inputs</li>
</ul>

<p><strong>Alert Conditions:</strong></p>
<pre>
// When any pressure level goes LOW:
// 1. LCD displays "LOW" for affected system
// 2. Status LED turns ON
// 3. Buzzer activates (unless muted)
// 4. Blink LED starts 1Hz blinking
</pre>

<p><strong>Mute Functionality:</strong></p>
<ul>
    <li>Press Mute Button: Temporarily silences buzzer</li>
    <li>Auto Reset: Buzzer unmutes on new alert conditions</li>
    <li>Visual Alert: LED indicators remain active during mute</li>
</ul>

<h2 class="emoji">🔧 Troubleshooting</h2>
<table>
    <thead>
        <tr>
            <th>Issue</th>
            <th>Possible Cause</th>
            <th>Solution</th>
        </tr>
    </thead>
    <tbody>
        <tr><td>LCD not displaying</td><td>Wrong pin connections</td><td>Verify PORTB 4-7 connections</td></tr>
        <tr><td>Buzzer not sounding</td><td>Incorrect buzzer polarity</td><td>Check buzzer positive/negative</td></tr>
        <tr><td>Sensors not detecting</td><td>Pull-up resistors missing</td><td>Add 10k pull-up resistors</td></tr>
        <tr><td>System resetting</td><td>Power supply instability</td><td>Use regulated 5V power supply</td></tr>
    </tbody>
</table>
<p><strong>Debugging Tips:</strong></p>
<ul>
    <li>Check all hardware connections</li>
    <li>Verify oscillator settings</li>
    <li>Use MPLAB debugger for step-by-step execution</li>
    <li>Monitor global variables in watch window</li>
</ul>

<h2 class="emoji">🤝 Contributing</h2>
<p>We welcome contributions! Please follow these steps:</p>
<ul>
    <li>Fork the repository</li>
    <li>Create a feature branch (<code>git checkout -b feature/AmazingFeature</code>)</li>
    <li>Commit your changes (<code>git commit -m 'Add some AmazingFeature'</code>)</li>
    <li>Push to the branch (<code>git push origin feature/AmazingFeature</code>)</li>
    <li>Open a Pull Request</li>
</ul>

<p><strong>Coding Standards:</strong></p>
<ul>
    <li>Follow existing naming conventions</li>
    <li>Use descriptive variable names</li>
    <li>Include comprehensive comments</li>
    <li>Test thoroughly before submitting</li>
</ul>

<h2 class="emoji">📄 License</h2>
<p>You may use, modify, and distribute freely.</p>

<h2 class="emoji">👨‍💻 Author</h2>
<p>
    Islam Nagi<br>
    Email: islam.nagi@example.com<br>
    GitHub: <a href="https://github.com/islamnagi">@islamnagi</a><br>
    LinkedIn: Islam Nagi
</p>

<div class="center">
    ⭐ Don't forget to star this repository if you find it helpful!<br>
    Built with ❤️ for reliable pressure monitoring systems
</div>

</body>
</html>
