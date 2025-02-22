# Aladin - CV-Job Matching System

A simple back-end system in C that matches job candidates' CVs with job openings, simulating an automated recruitment solution.

## Description
Aladin is a program designed to:
- Allow the registration of CVs with name, skills, and years of experience.
- Allow the registration of job openings with title, required skills, and minimum years of experience.
- Calculate compatibility between CVs and jobs based on matching skills and experience criteria.
- Display the most compatible jobs for each CV, simulating intelligent job matching.

This is a basic prototype, ideal for Back-end students learning C programming fundamentals. The project does not integrate directly with real job sites like LinkedIn or Indeed but simulates job searching with manually entered data.

## Code Structure
- **Structs**:
  - `Curriculo`: Stores name, skills (array of strings), years of experience, and number of skills.
  - `Vaga`: Stores title, required skills, minimum years of experience, and number of skills.
- **Functions**:
  - `adicionarCurriculo`: Allows the user to input CV data.
  - `adicionarVaga`: Allows input of job opening data.
  - `calcularMatch`: Calculates compatibility based on matching skills (in %) and adjusts for experience criteria.
  - `exibirMatches`: Displays the most compatible jobs for each CV.
- **Logic**:
  - Uses string comparisons (`strcmp`) to check for skill matches.
  - Adjusts the compatibility percentage based on experience (penalizes if insufficient, bonuses if excessive).

## How to Use
1. **Compile:**
2. **Run:**
- Windows: `aladin.exe`
- Linux/Mac: `./aladin`
3. Follow the interactive menu to:
- Add CVs (name, skills, years of experience).
- Add job openings (title, required skills, minimum years of experience).
- Display matches between CVs and jobs.
- Exit the program.
