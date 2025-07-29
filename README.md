# HardwareTrojanDetection

## Overview

**HardwareTrojanDetection** is a research-oriented toolkit designed to identify and analyze hardware Trojans in digital circuits using both simulation and static analysis methods. The project leverages Verilog-based circuit models and provides automated scripts for Trojan detection, feature extraction, and reporting. It is suitable for advanced users, researchers, and engineers working in hardware security and trust.

## Features

- **Automated Hardware Trojan Detection:** Supports detection of hardware Trojans in Verilog netlists through static and dynamic analysis.
- **Verilog Parsing & Analysis:** Efficient parsing of Verilog files to extract relevant circuit features and identify suspicious modules.
- **Simulation Integration:** Includes C-based simulation hooks for runtime behavioral analysis.
- **Feature Extraction:** Comprehensive extraction of circuit-level features for machine learning or rule-based analysis.
- **Extensible Analysis Pipeline:** Modular design allows integration with third-party verification tools and custom analysis scripts.
- **Reporting:** Generates detailed reports on detected Trojans, annotated netlists, and feature statistics.

## Dependencies

- **Python 3.8+**
  - `numpy`
  - `pandas`
  - `pyverilog` (for Verilog parsing)
- **C Compiler** (e.g., GCC) for simulation modules
- **Jupyter Notebook** (for interactive analysis and experimentation)
- **Verilog Simulation Tools** (optional, e.g., Icarus Verilog)

## Installation

```bash
git clone https://github.com/Tusharprabhu/HardwareTrojanDetection.git
cd HardwareTrojanDetection

# Python dependencies
pip install -r requirements.txt

# (Optional) Build C simulation modules
cd sim
make
```

## Usage

### Static Analysis

```bash
python verilogtrojan.py --input <verilog_file.v> --report <output_report.csv>
```

- `--input`: Path to the Verilog netlist.
- `--report`: Destination for the detection report.

### Simulation-based Detection

Integrate the C simulation module with your Verilog environment. Refer to the scripts in `sim/` and associated notebooks for example workflows.

### Feature Extraction

```bash
python feature_extractor.py --input <verilog_file.v> --output <features.csv>
```

### Interactive Analysis

Open and run the provided Jupyter notebooks in the root directory for exploratory analysis, visualization, and custom experiments.

## Architecture

```
HardwareTrojanDetection/
│
├── verilogtrojan.py       # Main detection script (Python)
├── feature_extractor.py   # Feature extraction utility (Python)
├── sim/                   # C simulation modules
├── notebooks/             # Jupyter Notebooks for interactive analysis
├── data/                  # Example Verilog files and datasets
├── reports/               # Output reports and logs
└── requirements.txt       # Python dependencies
```

- **Detection Pipeline:** The core detection logic is implemented in `verilogtrojan.py`, which parses the input netlist, extracts structural and logical features, applies detection heuristics, and outputs annotated reports.
- **Simulation Modules:** C programs in `sim/` enable runtime behavioral analysis and can be interfaced with Python scripts or invoked externally.
- **Feature Extraction:** `feature_extractor.py` provides modular extraction of features for downstream ML or analytical tasks.

## Contribution Guidelines

- Fork the repository and create feature branches for new developments.
- Follow PEP8 style for Python code and standard conventions for C modules.
- Document new functionalities in the relevant script/module and update the README if applicable.
- Submit pull requests with clear descriptions and associated test cases.
- Issues and suggestions should be filed via the GitHub issue tracker.

---

**Note:** This repository assumes familiarity with hardware security concepts, Verilog design, and Python/C development workflows. For further clarifications, consult the source code or reach out via GitHub issues.
