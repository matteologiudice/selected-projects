# Selected Academic Projects
→ [MSc in Cyber Risk Strategy and Governance (Joint Degree)](https://www.unibocconi.it/en/programs/master-science/cyber-risk-strategy-and-governance), Bocconi University & Politecnico di Milano<br>
→ This repository also includes selected academic work completed during my [BSc in Computer Engineering](https://corsilaurea22-23.unical.it/en/course/computer-engineering-2/index.html) at the University of Calabria and exchange experiences at Fairmont State University and the University of Rhode Island (USA)

---

## 🔎 Project Index

### Cybersecurity & Cyber Risk
- [CAN Bus Intrusion Detection System (IDS)](#can-bus-intrusion-detection-system--rule-based-detection-with-learned-benign-profiles)
- [Social Engineering Attack Simulation – Spear-Phishing & Credential Harvesting](#social-engineering-attack-simulation--spear-phishing--credential-harvesting)
- [Amazon Prime Air – Drone Delivery System Threat Model (STRIDE)](#amazon-prime-air--drone-delivery-system-threat-model-stride)
- [France – Smart Surveillance](#france--smart-surveillance-ai-related-cyber-risks--governance)
- [Ferrari Cyber Security Toolkit](#ferrari-cyber-security-toolkit-board-level)
- [NotPetya Impact Analysis – Maersk](#notpetya-impact-analysis--maersk-global-operations)
- [Ransomware Risk Modelling](#ransomware-risk-modelling-via-bayesian-network)

### AI & Data
- [Phishing URL Detection using Machine Learning](#phishing-url-detection-using-machine-learning)
- [Database Management Systems Project](#database-management-systems-project)

### Software Engineering
- [Online Auction System](#online-auction-system--distributed-clientserver-with-grpc--design-patterns)
- [ShoeApp – E-Commerce Platform](#secure-full-stack-e-commerce-platform--shoeapp)

### Control Systems & Engineering
- [Dynamic Systems Analysis and Control Modeling](#dynamic-systems-analysis-and-control-modeling)

### Computer Graphics
- [Asteroids – 2D Game](#asteroids--2d-game-with-hierarchical-collision-detection)

---

## CAN Bus Intrusion Detection System – Rule-Based Detection with Learned Benign Profiles

**Course:** Human and Physical Aspects of Security  
**Focus:** Automotive / in-vehicle network security, CAN bus intrusion detection, anomaly detection, explainable detection  
**Methodology:** Rule-based detection engine calibrated on benign traffic (global and per-CAN-ID behavioural profiles, additive multi-class scoring)  
**Technologies:** Python, pandas, NumPy, scikit-learn, Matplotlib  

**Detected Attack Classes:** DoS, Fuzzy, Spoofing, Masquerade, Replay  

**Description:**  
Intrusion Detection System for the automotive **CAN bus**. The detector is rule-based but data-driven: it learns a vehicle's *benign* behaviour from attack-free traffic only (per-ID timing, DLCs, payload ranges, reuse gaps, allowed ID transitions, persisted to a reusable JSON profile), then flags deviations through explainable per-class rules with additive scoring. Evaluated on six held-out labelled captures with accuracy, precision, recall and F1 score.

---

## Social Engineering Attack Simulation – Spear-Phishing & Credential Harvesting

**Course:** Human and Physical Aspects of Security  
**Focus:** Social engineering, OSINT, spear-phishing, adversary-in-the-middle (AiTM) phishing, credential & 2FA harvesting  
**Methodology:** OSINT-driven reconnaissance, structured *Objective–Finding–Source* intelligence model, Hadnagy social-engineering principles (authority, urgency, pretexting, rapport-building)  
**Technologies:** Python, Flask, browser automation, HTML/CSS/JS  

**Description:**  
End-to-end red-team-style social engineering exercise simulating a targeted attack against a security-aware individual. The scenario centres on compromising a victim's identity on a national tax-authority portal to redirect tax reimbursements to an attacker-controlled account, using organisations linked to the target as an indirect attack surface.

The project covers the full attack chain in three phases:
- **Reconnaissance (OSINT):** mapping of corporate ownership and governance structure around the target through public registries, corporate databases, search-engine dorking, archived web content, and email-pattern inference, to identify legal representatives, delegates, and external auditors as candidate targets. Intelligence was tracked with a structured *Objective / Finding / Source* model.
- **Phishing design:** a two-stage campaign — a low-effort replica of a legitimate institutional notification, followed by a tailored spear-phishing message exploiting an auditor–client authority relationship — each design choice explicitly mapped to established social-engineering principles.
- **Phishing infrastructure (PoC):** a cloned login portal reproducing the institution's federated digital-identity (SPID) flow, with a real-time adversary-in-the-middle relay that forwards captured credentials and second-factor responses (app approval, OTP token, QR code) to the legitimate service as the victim authenticates — defeating 2FA — and serves a convincing post-login interface to avoid raising suspicion.

> ⚠️ **Educational use only.** Carried out strictly as an academic exercise on a fictional, course-authorised scenario. The full report and source code are **not published**: they contain personally identifiable information (PII) of real individuals gathered via OSINT, and a functional credential-harvesting toolkit.

---

## Amazon Prime Air – Drone Delivery System Threat Model (STRIDE)

**Course:** Human and Physical Aspects of Security  
**Focus:** Threat modelling, attack surface analysis, cyber-physical & RF security, UAS/aviation security, qualitative risk assessment  
**Methodology:** STRIDE (Spoofing, Tampering, Repudiation, Information Disclosure, Denial of Service, Elevation of Privilege)  
**Tools:** OWASP Threat Dragon v2.6.2  

**Description:**  
Group threat model of **Amazon Prime Air**, Amazon's autonomous BVLOS drone delivery service built on the **MK27** fixed-wing VTOL airframe. The analysis is grounded in Amazon's publicly available FAA petition and structured around a full **Data Flow Diagram** — assets, actors, processes, data stores, external entities, and trust boundaries — modelled in OWASP Threat Dragon.

<p align="center">
  <img src="./img/THREAT MODEL.png" width="80%" />
</p>

📄 [Download PDF (Report)](./Threat_Model_Drone_Delivery_System_STRIDE.pdf)

---

## Dynamic Systems Analysis and Control Modeling

**Course:** Fundamentals of Control Systems
**Focus:** Linear systems analysis, state-space modeling, transfer functions, time/frequency response, continuous and discrete time systems  
**Technologies:** Wolfram Mathematica  

**Description:**  
Analytical project on linear time-invariant (LTI) dynamic systems, developed through both **continuous-time** and **discrete-time** state-space models. The work includes the study of natural modes, free and forced responses, transfer functions, poles and zeros, step/ramp/periodic input responses, and minimum-order input-output representations. The project also examines stability properties, transient and steady-state behavior, and the role of initial conditions in activating specific system modes. All symbolic and computational analyses were carried out using **Wolfram Mathematica**.

📄 [Download PDF (in Italian)](./Relazione_Tecnica_Progetto_FdA.pdf)

---

## France – Smart Surveillance: AI-Related Cyber Risks & Governance

**Course:** Institutional Scenarios of Cyber Risk  
**Focus:** AI-related cyber risk analysis, stakeholder mapping, policy & governance, regulatory compliance  
**Description:** Group project analyzing AI-related cyber risks in France, with a focus on smart surveillance systems. The work covers the national and EU regulatory landscape (AI Act, GDPR, Law Enforcement Directive), a full stakeholder analysis (citizens, government, technological supply chain), and a structured risk mapping across cybersecurity, economic, societal, and national security dimensions. The project proposes a governance framework centered around a newly designed national authority (HAIASP) and a 10-action resilience plan to secure the AI-based public video surveillance supply chain while safeguarding fundamental rights and public trust.

📄 [Download PDF](./FranceSmartSurveillance_final_version.pdf)

---

## Ferrari Cyber Security Toolkit (Board-Level)
**Course:** Strategy and Governance for Cyber Risk  
**Focus:** Cybersecurity governance, board awareness, investment justification  
**Description:** Development of a board-level cybersecurity toolkit aimed at supporting strategic decision-making and investment prioritization in cyber risk management

📄 [Download PDF](./ferrari-cyber-security-toolkit.pdf)

---

## Phishing URL Detection using Machine Learning

**Course:** Artificial Intelligence for Security  
**Focus:** Application of supervised, unsupervised, and anomaly detection techniques for phishing URL detection, based on the analysis of structural and lexical characteristics of web addresses<br>
**Description:** Exploratory Data Analysis (EDA), feature engineering on URL attributes, categorical feature encoding (One-Hot Encoding and Target Encoding), and implementation of supervised classifiers, unsupervised learning approaches, and anomaly detection methods


📄 [Download Jupyter Notebook](./AI_for_Security_Project.ipynb)

---

## NotPetya Impact Analysis – Maersk Global Operations
**Course:** Technology Risk Governance  
**Focus:** Post-incident analysis, systemic risk, business impact  
**Methods:** Fault Tree Analysis (FTA), Swiss Cheese Model, Bow-Tie Analysis, Business Impact Analysis (BIA)

📄 [Download PDF](./notpetya-maersk-risk-analysis.pdf)

---

## Ransomware Risk Modelling via Bayesian Network
**Course:** Methods and Data Analytics for Risk Assessment  
**Focus:** Probabilistic cyber risk modelling in a financial institution  
**Methods:** Bayesian Network, scenario analysis, control effectiveness evaluation

📄 [Download PDF (Presentation)](./ransomware-bayesian-network.pdf)
📄 [Download PDF (Paper)](./Methods_Paper.pdf)

---

## Database Management Systems Project
**Course:** Enterprise ICT Architectures  
**Technologies:** SQL, Neo4j, MongoDB<br>
**Description:** Comparative analysis and implementation of relational, graph database systems and document-based

📄 [Download PDF (ER model + SQL queries)](./EICTA_Project_1___ER_Model___SQL.pdf)

📄 [Download PDF (Neo4j + BPMN)](./EICTA_Project_2___NEO4j___BPMN.pdf)

📄 [Download PDF (MongoDB)](./EICTA_Project_3___MongoDB.pdf)

---

## Online Auction System – Distributed Client–Server with gRPC & Design Patterns  

**Course:** Software Engineering  
**Focus:** Distributed systems architecture, remote procedure calls, object-oriented design, modularity, testing  

**Programming Language:** Java  
**Technologies:** Google gRPC (Remote Procedure Calls), JUnit  

**Design Patterns Implemented:** Decorator, Builder, Bridge, Composite, Observer  

**Description:**  
Design and implementation of a distributed **online auction system** developed in Java using **Google gRPC** for client–server communication via remote procedure calls (RPC). The project emphasizes modular software architecture and object-oriented design, applying classical design patterns to improve maintainability, extensibility, and separation of concerns.

The work includes **functional and non-functional requirements** definition and prioritization, **UML modeling for each module**, and systematic **unit testing** of modules and features using **JUnit**.

💻 [Open Repository](https://github.com/matteologiudice/Progetto-ING-SOFTWARE-Matteo-Lo-Giudice-231752)

---

## Secure Full-Stack E-Commerce Platform – ShoeApp  

**Course:** Software Platforms for Web Applications  
**Focus:** Secure full-stack development, REST API design, SQL database integration, token-based authentication  
**Technologies:** Java (Spring Boot), PostgreSQL, Angular, Keycloak (OAuth2 / JWT), Google Maps API  

**Description:**  
Design and implementation of a complete full-stack e-commerce platform for online shoe retail. The backend exposes RESTful APIs developed in Java (Spring Boot) and connected to a PostgreSQL relational database (SQL-compliant and database-agnostic architecture). Authentication and authorization are enforced via Keycloak using OAuth2/OpenID Connect with JWT-based stateless access control. The Angular frontend implements product catalog browsing, persistent cart management (including guest-to-authenticated cart merging upon login), user profile, order history, checkout workflow, order confirmation, and Google Maps API integration for location-based services.

<p align="center">
  <img src="./img/webapp1.png" width="45%" />
  <img src="./img/webapp2.png" width="45%" />
</p>

💻 [Frontend Repository](https://github.com/matteologiudice/ShoeApp_WebApplication_FrontEnd) 

⚙️ [Backend Repository](https://github.com/matteologiudice/ShoeApp_WebApplication_BackEnd)

---

## Asteroids – 2D Game with Hierarchical Collision Detection  

**Course:** CSC 406 – Computer Graphics  
**Focus:** Real-time graphics, physics-based animation, collision detection, object-oriented design  

**Programming Language:** C++  
**Libraries & Tools:** OpenGL, GLUT, TGA image textures  

**Techniques Implemented:**
- Hierarchical bounding boxes for optimized collision detection  
- Euclidean distance-based collision checks  
- Physics-based animation using state equations (position, velocity, angular velocity)  
- Mouse-driven dynamic orientation control  
- Spherical world model (screen wrapping mechanics)  
- Linked list data structures for asteroid and missile management  
- Texture-based rendering (.tga images)  
- Real-time score, lives, and health tracking system  

**Description:**  
Development of a 2D *Asteroids*-style game featuring a physics-driven spaceship with thrust and rotational controls, hierarchical collision detection, missile management, dynamically generated asteroids with probabilistic spawning, and additional adversarial entities. The project emphasizes structured object-oriented programming, real-time interaction handling, and computational optimization for collision detection

<p align="center">
  <img src="./img/game1.png" width="40%" />
  <img src="./img/game2.png" width="40%" />
</p>

👽 [Open Project Directory](./Computer-Graphics/Asteroids)

📄 [Download PDF Report](./Computer-Graphics/Asteroids/report/Report_Programming_Assignment_3_Matteo_Lo_Giudice.pdf)


